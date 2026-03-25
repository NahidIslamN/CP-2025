#include <bits/stdc++.h>
using namespace std;

int ask(int i, int j) {
    cout << "? " << i << " " << j << endl;
    cout.flush();

    int x;
    cin >> x;
    if(x == -1) exit(0);
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        int ans = -1;


        int res = ask(1, 2);
        if(res == 1) ans = 1;
        if(ans == -1) {
            res = ask(2, 3);
            if(res == 1) ans = 2;
        }
        if(ans == -1) {
            res = ask(1, 3);
            if(res == 1) ans = 1;
        }

        for(int i = 4; i <= 2 * n - 1 && ans == -1; i += 2) {
            res = ask(i, i + 1);
            if(res == 1) {
                ans = i;
            }
        }

        if(ans == -1) ans = 2 * n;

        cout << "! " << ans << endl;
        cout.flush();
    }

    return 0;
}
