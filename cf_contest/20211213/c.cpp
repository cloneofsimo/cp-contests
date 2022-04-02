#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll arr[200010];
int k, n;


ll eval(vector<ll>& v) {
    ll ans = 0;
    ans += max(v[n], (ll)0);
    // make v to list
    list<ll> l;
    for (int i = 0; i < n + 1; i++) {
        l.push_back(v[i]);
    }
    // remove k ele from list from back
    for (int i = 0; i < k; i++) {
        if (l.back() == 0) break;
        l.pop_back();
    }
    while (l.back() != 0) {
        ans += l.back() * 2;
        for (int i = 0; i < k; i++) {

            if (l.back() == 0) break;
            l.pop_back();
        }
    }
    while (l.front() != 0) {
        ans -= l.front() * 2;
        for (int i = 0; i < k; i++) {

            if (l.front() == 0) break;
            l.pop_front();
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    while (T--) {
        cin >> n >> k;
        for (int i = 0; i < n; i++) cin >> arr[i];
        arr[n] = 0;
        sort(arr, arr + n + 1);
        // index of 0
        // make arr into vector
        vector<ll> v;
        for (int i = 0; i < n + 1; i++) {
            v.push_back(arr[i]);
        }
        ll ans = eval(v);
        // reverse
        reverse(v.begin(), v.end());
        for (int i = 0; i < n + 1; i++) {
            v[i] = -v[i];
        }
        ll ans2 = eval(v);

        cout << min(ans, ans2) << '\n';

    }

}