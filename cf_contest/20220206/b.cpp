#include <bits/stdc++.h>
using namespace std;
using ll = long long;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        ll y;
        ll n, x; cin >> n >> x >> y;
        ll oddity = 0;
        for (ll i = 0; i < n; i++) {
            ll t; cin >> t;
            oddity += t;
        }
        if ((oddity + y + x) % 2 == 0) {
            cout << "Alice\n";
        }
        else {
            cout << "Bob\n";
        }

    }


}