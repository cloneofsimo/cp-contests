#include <bits/stdc++.h>
using namespace std;

int n, q, tota, pos;
char c;
string S;

int vid(int h) {
    if (h < 0 || h >= n) return 0;
    return 1;
}

int touchs(int here) {
    // check if here has abc nearby
    if (S[here] == 'a') {
        if (vid(here + 1) && vid(here + 2) && S[here + 1] == 'b' && S[here + 2] == 'c') return 1;
    }
    if (S[here] == 'b') {
        if (vid(here - 1) && vid(here + 1) && S[here - 1] == 'a' && S[here + 1] == 'c') return 1;
    }
    if (S[here] == 'c') {
        if (vid(here - 1) && vid(here - 2) && S[here - 1] == 'b' && S[here - 2] == 'a') return 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    cin >> S;

    for (int i = 0; i < n - 2; i++) {
        if (S[i] == 'a' && S[i + 1] == 'b' && S[i + 2] == 'c') {
            tota += 1;
        }
    }
    while (q--) {
        cin >> pos >> c;
        int was_abc = touchs(pos - 1);
        S[pos - 1] = c;
        int now_abs = touchs(pos - 1);
        tota += now_abs - was_abc;
        cout << tota << '\n';
    }

}