#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        set<pair<int,int>> edges;  
        const int MAX_PATHS = 230; 

        for (int k = 1; k <= MAX_PATHS; k++) {
            cout << "? " << k << endl;
            cout.flush();

            int q;
            cin >> q;

            if (q == -1) exit(0); 
            if (q == 0) break; 

            vector<int> path(q);
            for (int i = 0; i < q; i++) cin >> path[i];

            
            for (int i = 0; i < q-1; i++) {
                edges.insert({path[i], path[i+1]});
            }
        }

       
        cout << "! " << edges.size() << "\n";
        for (auto &e : edges) {
            cout << e.first << " " << e.second << "\n";
        }
        cout.flush();
    }
    return 0;
}