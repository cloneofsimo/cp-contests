#include <bits/stdc++.h>
using namespace std;

int arr[10010], brr[10010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) cin >> arr[i];
        for (int i = 0; i < n; i++) cin >> brr[i];

        int max_a = 0;
        for (int i = 0; i < n; i++) {
            max_a = max(max_a, arr[i]);
        }
        int max_b = 0;
        for (int i = 0; i < n; i++) {
            max_b = max(max_b, brr[i]);
        }
        int max_l = 0;
        for (int i = 0; i < n; i++) {
            int m_l = min(arr[i], brr[i]);
            max_l = max(max_l, m_l);
        }




        int ans = max(max_a, max_b);

        cout << ans * max_l << '\n';


    }

}