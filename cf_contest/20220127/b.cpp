#include <bits/stdc++.h>
using namespace std;
int arr[200100], n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> arr[i];
        int ptr = n - 1;
        int ans = 0;
        int ans_val = arr[n - 1];

        while (ptr >= 0) {
            while (arr[ptr] == ans_val) {
                ptr--;
                if (ptr == -1) {
                    goto END;
                }
            }
            ans += 1;
            ptr -= (n - 1 - ptr);


        }
    END:;
        cout << ans << '\n';


    }
}