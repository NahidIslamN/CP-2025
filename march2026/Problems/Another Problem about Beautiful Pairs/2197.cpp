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
        vector<long long> a(n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        long long ans = 0;
        int B = (int)sqrt((long double)n) + 1;
        for (int x = 1; x <= B; ++x) {
            for (int j = 1; j <= n; ++j) {
                long long i = j - 1LL * x * a[j];
                if (i >= 1 && i < j && a[i] == x) {
                    ++ans;
                }
            }
        }

        for (int i = 1; i <= n; ++i) {
            if (a[i] <= B) continue;
            long long limit = (n - i) / a[i];
            for (long long y = 1; y <= limit; ++y) {
                int j = (int)(i + a[i] * y);
                if (a[j] == y) {
                    ++ans;
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
