#include <bits/stdc++.h>
using namespace std;
#define N 1010

int root[N], sz[N];
int n, d;
int find(int a) {
    if (root[a] == a) return a;
    return root[a] = find(root[a]);
}

int uni_with_size(int a, int b) {
    int ra = find(a), rb = find(b);
    if (ra == rb) return sz[ra];
    if (sz[ra] > sz[rb]) {
        root[rb] = ra;
        sz[ra] += sz[rb];
        return sz[ra];
    }
    else {
        root[ra] = rb;
        sz[rb] += sz[ra];
        return sz[rb];
    }
}

int ctr[N];

int topkgp(int r) {
    for (int i = 0; i <= n; i++) {
        ctr[i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        ctr[find(i)]++;
    }
    sort(ctr + 1, ctr + n + 1, greater<int>());
    int ans = 0;
    for (int i = 1; i <= r; i++) {
        ans += ctr[i];
    }
    return ans;

}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> d;
    for (int i = 1; i <= n; i++) {
        root[i] = i;
        sz[i] = 1;
    }
    int mszs = 1;
    int res = 1;

    for (int i = 0; i < d; i++) {
        int x1, y1; cin >> x1 >> y1;
        if (find(x1) == find(y1)) {
            res += 1;

        }
        else {
            int szs = uni_with_size(x1, y1);
            mszs = max(mszs, szs);
        }
        cout << topkgp(res) - 1 << '\n';

    }

}