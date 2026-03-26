#include <bits/stdc++.h>
using namespace std;

static long long sumSmallest(vector<int> v, int cnt) {
    if (cnt <= 0) return 0;
    sort(v.begin(), v.end());
    long long s = 0;
    for (int i = 0; i < cnt; i++) s += v[i];
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k, p, m;
        cin >> n >> k >> p >> m;

        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];

        int win = a[p];

        vector<int> before;
        before.reserve(max(0, p - 1));
        for (int i = 1; i < p; i++) before.push_back(a[i]);
        int needFirst = max(0, p - k);
        long long firstSetup = sumSmallest(before, needFirst);
        long long firstWinCost = firstSetup + win;

        if (firstWinCost > m) {
            cout << 0 << '\n';
            continue;
        }
        vector<int> nonWin;
        nonWin.reserve(n - 1);
        for (int i = 1; i <= n; i++) {
            if (i != p) nonWin.push_back(a[i]);
        }
        int needCycle = n - k;
        long long cycleSetup = sumSmallest(nonWin, needCycle);
        long long perExtraWin = cycleSetup + win;

        long long ans = 1 + (m - firstWinCost) / perExtraWin;
        cout << ans << '\n';
    }

    return 0;
}
