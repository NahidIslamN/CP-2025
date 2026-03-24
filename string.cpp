#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin >> a[i];

        ll count = 0;
        for(int i=0;i<n;i++){
            for(int k=1;i + a[i]*k < n;k++){
                int j = i + a[i]*k;
                if(a[j] == k) count++;
            }
        }
        cout << count << "\n";
    }
}