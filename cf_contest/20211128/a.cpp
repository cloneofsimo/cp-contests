#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll arr[30];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll T; cin >> T;
    while (T--) {
        ll n; cin >> n;
        ll pow2 = 1;

        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
            while (arr[i] % 2 == 0) {
                arr[i] /= 2;
                pow2 *= 2;
            }

        }
        sort(arr, arr + n);
        ll ans = 0;
        for (ll i = 0; i < n - 1; i++) {
            ans += arr[i];
        }
        ans += arr[n - 1] * pow2;

        cout << ans << '\n';

    }

}