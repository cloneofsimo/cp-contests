#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        string S; cin >> S;
        int n = S.length();
        bool is_toable = false;
        int i;
        for (i = n - 1; i >= 1; i--) {
            if (S[i] - '0' + S[i - 1] - '0' >= 10) {
                is_toable = true;
                break;
            }
        }
        if (is_toable) {
            cout << S.substr(0, i - 1);
            cout << S[i - 1] - '0' + S[i] - '0';
            cout << S.substr(i + 1);

        }
        else {
            cout << S[0] - '0' + S[1] - '0';
            cout << S.substr(2);
        }
        cout << '\n';
    }

}