#include <bits/stdc++.h>

using namespace std;

const int N = 32768;
const int n = 15;

int arr[32769];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m; cin >> m;
    for (int i = 0; i < m; i++) cin >> arr[i];

    for (int i = 0; i < m; i++) {
        int x = arr[i];

        if (x == 0) {

            cout << 0 << ' ';
        }
        else {
            int minans = N + 10;
            for (int j = 0; j < 16; j++) {
                int n_mult = 0;
                int _j = j + x;
                while (_j % 2 == 0) {
                    n_mult += 1;
                    _j /= 2;
                }
                minans = min(minans, j + 15 - n_mult);
            }
            cout << minans << ' ';
        }
    }

}