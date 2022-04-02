#include <bits/stdc++.h>
using namespace std;

void testcase() {
    int n; cin >> n;
    vector<int> sides(n);
    for (int i = 0; i < n; i++) {
        cin >> sides[i];
    }
    int ans = 0;
    sort(sides.begin(), sides.end());
    for (int i = 0; i < n; i++) {
        if (sides[i] > ans) {
            ans += 1;
        }

    }
    cout << ans << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    for (int _t = 0; _t < T; _t++) {
        cout << "Case #" << _t + 1 << ": ";
        testcase();
    }
}