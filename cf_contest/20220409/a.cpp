#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int arr[26], brr[26], tarr[26], tbrr[26];

void testcase() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> brr[i];
    }

    ll ans = 0;

    for (int i = 0; i < n - 1; i++) {
        if (abs(arr[i + 1] - arr[i]) + abs(brr[i + 1] - brr[i]) > abs(arr[i + 1] - brr[i]) + abs(brr[i + 1] - arr[i])) {
            ans += abs(arr[i + 1] - brr[i]) + abs(brr[i + 1] - arr[i]);
        }
        else {
            ans += abs(arr[i + 1] - arr[i]) + abs(brr[i + 1] - brr[i]);
        }
    }

    cout << ans << '\n';


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    for (int _t = 0; _t < T; _t++) {
        testcase();
    }
}