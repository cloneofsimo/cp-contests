#include <bits/stdc++.h>
using namespace std;

int arr[120];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) cin >> arr[i];
        int ans = 1;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 1) {
                ans += 1;
                if (i > 0 && arr[i - 1] == 1) ans += 4;

            }
            else {
                if (i > 0 && arr[i - 1] == 0) {
                    ans = -1;
                    break;
                }
            }
        }
        cout << ans << '\n';

    }

}