#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int ans = 0;
        int cur = a[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (a[i] > cur) {
                ans += 1;
                cur = a[i];
            }
        }
        cout << ans << '\n';
    }

}