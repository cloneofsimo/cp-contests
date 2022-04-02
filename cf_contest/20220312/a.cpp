#include <bits/stdc++.h>
using namespace std;


int main() {
    int T; cin >> T;
    while (T--) {
        string S1, S2;
        int sum1 = 0, sum2 = 0;
        int n; cin >> n;
        S1 = "";
        S2 = "";
        int cnt = n;
        int tgl = 0;
        while (cnt > 0) {
            S1 += tgl % 2 ? '1' : '2';
            cnt -= tgl % 2 ? 1 : 2;
            tgl += 1;
        }
        if (cnt == 0) {
            cout << S1 << '\n';
        }
        else {
            cnt = n;
            tgl = 0;
            while (cnt > 0) {
                S2 += tgl % 2 ? '2' : '1';
                cnt -= tgl % 2 ? 2 : 1;
                tgl += 1;
            }
            cout << S2 << '\n';
        }
    }
}