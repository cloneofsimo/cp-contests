#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        string S; cin >> S;
        int start = 0;
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == 'N') {
                start += 1;
            }
        }
        if (start != 1) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }
}