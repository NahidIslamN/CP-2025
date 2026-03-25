#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        int ones = 0;
        for (char c : s) {
            if (c == '1') ones++;
        }
        
        int totalOnes = ones * (n - 1) + (n - ones);
        cout << totalOnes << '\n';
    }

    return 0;
}
