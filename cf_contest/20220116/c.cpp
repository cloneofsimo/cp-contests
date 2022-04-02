#include <bits/stdc++.h>
using namespace std;
#define N 105
using ll = long long;


int root[N], tmm[N], ht[N];

int find(int x) {
    if (root[x] == x) return x;
    return root[x] = find(root[x]);
}

int uni(int x, int y) {
    int rx = find(x);
    int ry = find(y);
    if (rx == ry) return 0;
    root[rx] = ry;
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            root[i] = i;
            cin >> tmm[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> ht[i];
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (tmm[j] - tmm[i] < ht[j]) {
                    for (int k = i; k <= j; k++) {
                        uni(i, k);
                    }
                }
            }
        }
        int running_grp = -1;
        for (int i = 0; i < n; i++) find(i);
        ll ans = 0;
        ll local_tmm = 0;
        for (int i = 0; i < n; i++) {
            if (running_grp != find(i)) {
                running_grp = find(i);
                ans += (local_tmm * (local_tmm + 1)) / 2;
                local_tmm = (ll)ht[i];
            }
            else {
                local_tmm += (ll)(tmm[i] - tmm[i - 1]);
            }
        }
        ans += (local_tmm * (local_tmm + 1)) / 2;
        cout << ans << '\n';
    }
}