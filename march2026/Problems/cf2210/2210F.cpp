#include <bits/stdc++.h>
using namespace std;

long long countInversions(vector<int>& arr) {
    long long invt = 0;
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] > arr[j]) invt++;
        }
    }
    return invt;
}

long long f(vector<int>& b) {
    int m = b.size();
    if (m == 1) return 0;
    if (m > 20) return 0;
    
    long long max_invt = 0;
    
    for (long long mask = 0; mask < (1LL << (m - 1)); ++mask) {
        vector<int> c(m);
        int min_value = b[0];
        int max_value = b[0];
        c[0] = b[0];
        
        for (int i = 1; i < m; ++i) {
            min_value = min(min_value, b[i]);
            max_value = max(max_value, b[i]);
            
            if (mask & (1LL << (i - 1))) {
                c[i] = max_value;
            } else {
                c[i] = min_value;
            }
        }
        
        long long inv = countInversions(c);
        max_invt = max(max_invt, inv);
    }
    
    return max_invt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, q;
        cin >> n >> q;
        
        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }
        
        for (int i = 0; i < q; ++i) {
            int l, r;
            cin >> l >> r;
            l--; r--; 
            
            vector<int> sub(p.begin() + l, p.begin() + r + 1);
            cout << f(sub) << '\n';
        }
    }
    
    return 0;
}
