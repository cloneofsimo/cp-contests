#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n, k; cin >> n >> k;
        if (n == 4 && k == 3) {
            cout << -1 << '\n';
            continue;
        }
        if (n - 1 == k) {
            cout << 0 << ' ' << n - 2 << '\n';
            cout << 1 << ' ' << n - 1 << '\n';
            int m = n / 2;
            cout << m - 2 << ' ' << m - 1 << '\n';
            cout << m << ' ' << m + 1 << '\n';
            for (int i = 2; i <= m - 3; i++) {
                cout << i << ' ' << n - 1 - i << '\n';
            }
        }
        else {
            cout << k << ' ' << n - 1 << '\n';
            for (int i = 1; i < n / 2; i++) {
                if (k == i || k == n - 1 - i) {
                    continue;
                }
                else {
                    cout << i << ' ' << n - 1 - i << '\n';
                }
            }
            if (k != 0) cout << 0 << ' ' << n - 1 - k << '\n';
        }
    }
}