#include <bits/stdc++.h>
using namespace std;

struct Builder {
    int n, k, b;
    int s; // core size = n - b
    int x; // number of odd vertices among singleton side (bridge-tree odds)
    int q; // odd vertices needed inside core
    vector<pair<int, int>> edges;

    static bool core_possible(int s, int x, int q) {
        if (q < 0 || q > s) return false;
        if (((q ^ x) & 1) != 0) return false; // parity of odd count in core must match x
        if (s == 1) return q == (x & 1);
        if (s == 2) return false; // impossible as 2-vertex simple connected graph has 1 bridge
        if (s == 3) return x >= q; // triangle + attachments can realize these
        return true; // s >= 4 always constructible for valid parity/range
    }

    void build_core(vector<int>& attach_vertices) {
        attach_vertices.clear();

        if (s == 1) {
            attach_vertices.assign(x, 1);
            return;
        }

        if (s == 3) {
            // triangle
            edges.push_back({1, 2});
            edges.push_back({2, 3});
            edges.push_back({3, 1});

            vector<int> cnt(4, 0);
            for (int v = 1; v <= q; v++) cnt[v] = 1;
            cnt[1] += (x - q); // x and q parity match, so this preserves target parity

            for (int v = 1; v <= 3; v++) {
                for (int c = 0; c < cnt[v]; c++) attach_vertices.push_back(v);
            }
            return;
        }

        // s >= 4: start from a cycle (0 bridges in core)
        for (int v = 1; v < s; v++) edges.push_back({v, v + 1});
        edges.push_back({s, 1});

        // put all core-side bridge incidences on vertex 1
        attach_vertices.assign(x, 1);

        int p = x & 1;       // current odd count in core from attachments
        int r = (q - p) / 2; // number of extra odd pairs to create by adding chords

        if (r <= 0) return;
        if (r == 1) {
            if (p == 0) edges.push_back({1, 3});
            else edges.push_back({2, 4});
            return;
        }

        vector<int> even_vertices;
        if (p == 1) {
            for (int v = 2; v <= s; v++) even_vertices.push_back(v);
        } else {
            for (int v = 1; v <= s; v++) even_vertices.push_back(v);
        }

        for (int i = 0; i < r; i++) {
            edges.push_back({even_vertices[i], even_vertices[i + r]});
        }
    }

    bool build() {
        edges.clear();

        if (k & 1) return false;     // sum of degrees parity
        if (b == n - 2) return false; // impossible bridge count for connected simple graph

        s = n - b;
        x = -1;

        if (b == 0) {
            x = 0;
            if (!core_possible(s, x, k)) return false;
        } else {
            int lo = max(1, k - s);
            int hi = min(b, k);
            for (int cand = lo; cand <= hi; cand++) {
                if (core_possible(s, cand, k - cand)) {
                    x = cand;
                    break;
                }
            }
            if (x == -1) return false;
        }

        q = k - x;

        vector<int> attach_vertices;
        build_core(attach_vertices);

        if (b > 0) {
            vector<int> singles;
            singles.reserve(b);
            for (int v = s + 1; v <= n; v++) singles.push_back(v);

            int path_len = b - x + 1; // one path contributes odd endpoints
            vector<int> path_nodes(singles.begin(), singles.begin() + path_len);
            vector<int> leaf_nodes(singles.begin() + path_len, singles.end());

            vector<int> singleton_neighbors;
            singleton_neighbors.reserve(x);
            singleton_neighbors.push_back(path_nodes[0]);
            for (int v : leaf_nodes) singleton_neighbors.push_back(v);

            if ((int)attach_vertices.size() != x || (int)singleton_neighbors.size() != x) return false;

            for (int i = 0; i < x; i++) {
                edges.push_back({attach_vertices[i], singleton_neighbors[i]});
            }
            for (int i = 0; i + 1 < path_len; i++) {
                edges.push_back({path_nodes[i], path_nodes[i + 1]});
            }
        }

        return (int)edges.size() <= 5 * n;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        Builder solver;
        cin >> solver.n >> solver.k >> solver.b;

        if (!solver.build()) {
            cout << "No\n";
            continue;
        }

        cout << "Yes\n";
        cout << solver.edges.size() << '\n';
        for (auto [u, v] : solver.edges) {
            cout << u << ' ' << v << '\n';
        }
    }

    return 0;
}
