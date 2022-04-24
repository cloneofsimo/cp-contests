#include <bits/stdc++.h>
using namespace std;

void testcase() {
    int num_ones = 1;
    string S = "00000000";

    while (num_ones) {
        S = "00000000";
        // make random S with length 8 with num_ones ones
        for (int i = 0; i < num_ones; i++) {
            while (true) {
                int idx = rand() % 8;
                if (S[idx] == '0') {
                    S[idx] = '1';
                    break;
                }
            }
        }
        cout << S << endl;
        cin >> num_ones;
    }
}

int main() {

    int T; cin >> T;
    for (int _t = 0; _t < T; _t++) {
        //cout << "Case #" << _t + 1 << ": ";
        testcase();
    }
}