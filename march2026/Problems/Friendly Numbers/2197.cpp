#include <bits/stdc++.h>
using namespace std;

int sum_of_digits(long long y) {
    int sum = 0;
    while (y > 0) {
        sum += y % 10;
        y /= 10;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        long long x;
        cin >> x;

        int count = 0;
        for (long long y = x; y <= x + 81; ++y) {
            if (y - sum_of_digits(y) == x) {
                count++;
            }
        }

        cout << count << "\n";
    }

    return 0;
}