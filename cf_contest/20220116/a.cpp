#include <bits/stdc++.h>

using namespace std;

int main() {
    int T; cin >> T;
    while (T--) {
        string S; cin >> S;

        map<char, int> app;
        for (int i = 0; i < S.length(); i++) {
            app[S[i]]++;
        }
        for (auto it = app.begin(); it != app.end(); it++) {
            if (it->second < 2) {
                cout << it->first;
            }
            else {
                cout << it->first << it->first;
            }
        }
        cout << '\n';

    }
}