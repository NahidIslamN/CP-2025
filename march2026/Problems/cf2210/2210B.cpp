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
        
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            p[i]--;
        }
        
        int ans = 0;
        
        for (int mask = 0; mask < (1 << n); mask++) {
            vector<bool> marked(n, false);
            int sits = 0;
            for (int i = 0; i < n; i++) {
                if (marked[i]) {
                   
                    break;
                }
                
                if (mask & (1 << i)) {
                    sits++;
                    marked[p[i]] = true;
                }
            }
            
            ans = max(ans, sits);
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}
