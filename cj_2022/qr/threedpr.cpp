#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    int clr[3][4];
    for (int _t = 0; _t < T; _t++) {
        cout << "Case #" << _t + 1 << ": ";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> clr[i][j];
            }
        }
        int maxc[4];
        for (int i = 0; i < 4; i++) {
            maxc[i] = clr[0][i];
            for (int j = 1; j < 3; j++) {
                maxc[i] = min(maxc[i], clr[j][i]);
            }
        }
        if (maxc[0] + maxc[1] + maxc[2] + maxc[3] < 1000000) {
            cout << "IMPOSSIBLE" << '\n';
            continue;
        }
        int rem = 1000000;
        for (int i = 0; i < 4; i++) {
            if (maxc[i] > rem) {
                cout << rem << ' ';
                rem = 0;
            }
            else {
                cout << maxc[i] << ' ';
                rem -= maxc[i];
            }
        }
        cout << '\n';
    }
}