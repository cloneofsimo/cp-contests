#include <bits/stdc++.h>
using namespace std;

char cards[50][50];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            int ro = i % 2;
            int co = j % 2;
            char cur = ' ';
            if (!ro && !co) cur = '+';
            if (!ro && co) cur = '-';
            if (ro && !co) cur = '|';
            if (ro && co) cur = '.';
            cards[i][j] = cur;
        }
    }
    cards[0][0] = '.';
    cards[0][1] = '.';
    cards[1][0] = '.';
    cards[1][1] = '.';




    for (int t = 0; t < T; t++) {
        int r, c; cin >> r >> c;
        cout << "Case #" << t + 1 << ":" << '\n';
        for (int i = 0; i < 2 * r + 1; i++) {
            for (int j = 0; j < 2 * c + 1; j++) {
                cout << cards[i][j];
            }
            cout << '\n';
        }
    }
}