#include <bits/stdc++.h>
using namespace std;

int lnth[1003];

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int mmidx = -1;
        int mmval = -1;
        bool is_all_eq = true;
        int icnt = 0;
        for (int i = 3; i <= n; i++) {
            cout << "? " << 1 << ' ' << 2 << ' ' << i << '\n';
            int tmp; cin >> tmp;
            if (tmp > mmval) {
                mmval = tmp;
                mmidx = i;
                icnt++;
            }

        }

        if (icnt == 1) {
            // either 1,2 is min & max or other values are const (and min or max)
            cout << "? " << 1 << ' ' << 3 << ' ' << 4 << '\n';
            int tmp1; cin >> tmp1;
            if (tmp1 == -1) return 0;
            cout << "? " << 2 << ' ' << 3 << ' ' << 4 << '\n';
            int tmp2; cin >> tmp2;
            if (tmp2 == -1) return 0;

            if (tmp1 == mmval && tmp2 == mmval) {
                cout << "! " << 1 << ' ' << 2 << '\n';
                continue;
            }
        }

        // mmidx is max or min.
        int new_mmidx = -1;
        int new_mmval = -1;
        int cnt = 0;
        for (int i = 2; i <= n; i++) {
            if (i == mmidx) continue;
            cout << "? " << mmidx << ' ' << 1 << ' ' << i << '\n';
            int tmp; cin >> tmp;
            if (tmp == -1) return 0;
            if (tmp > new_mmval) {
                new_mmval = tmp;
                new_mmidx = i;
                cnt++;
            }
        }
        // now is 1 the minimum?

        if (cnt == 1)
            cout << "! " << new_mmidx << ' ' << 1 << '\n';
        else
            cout << "! " << mmidx << ' ' << new_mmidx << '\n';
    }
}