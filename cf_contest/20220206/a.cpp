#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n, k; cin >> n >> k;
        string S; cin >> S;
        int is_pallindrome = 1;
        for (int i = 0;i < n;i++) {
            if (S[i] != S[n - i - 1]) { is_pallindrome = 0; break; }
        }


        if (is_pallindrome) cout << 1 << '\n';
        else {
            if (k == 0) cout << 1 << '\n';
            else { cout << 2 << '\n'; }

        }
    }


}