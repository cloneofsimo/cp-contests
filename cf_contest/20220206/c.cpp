#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n, k; cin >> n >> k;
        int TOT = (n * k * (n * k + 1)) / 2;
        bool NO = false;
        if (n % 2 && k > 1) NO = true;

        if (NO) {
            cout << "NO\n";
            continue;
        }
        else {
            cout << "YES\n";
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < k; j++) {
                    cout << i + j * n + 1 << ' ';
                }
                cout << '\n';
            }
        }

    }
}