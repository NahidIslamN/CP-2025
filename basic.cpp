#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<int> p(n+1);
        for (int i = 1; i <= n; i++) cin >> p[i];

        vector<long long> pref(n+1, 0);

        int mn = p[1], mx = p[1];

        for (int i = 2; i <= n; i++) {
            pref[i] = pref[i-1];

            if (p[i] < mn) {
                pref[i] += (mx - p[i]);
                mn = p[i];
            } 
            else if (p[i] > mx) {
                pref[i] += (p[i] - mn);
                mx = p[i];
            }
        }

        while (q--) {
            int l, r;
            cin >> l >> r;
            cout << pref[r] - pref[l] << '\n';
        }
    }
}