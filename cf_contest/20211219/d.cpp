#include <bits/stdc++.h>
using namespace std;
#define N 500005

vector<int> indexset[N];
int arr[N];
int root[N];
int cnt = 0;


int find(int x) {
    if (root[x] == x) return x;
    return root[x] = find(root[x]);
}

int _union(int x, int y) {
    int rx = find(x);
    int ry = find(y);
    if (rx == ry) return rx;
    root[rx] = ry;
    return ry;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q; cin >> q;
    for (int i = 0; i < N; i++) {
        root[i] = i;
    }

    while (q--) {
        int tp; cin >> tp;
        if (tp == 1) {
            int x; cin >> x;
            root[cnt] = cnt;
            indexset[x].push_back(cnt);
            arr[cnt] = x;
            cnt++;
        }
        else {
            int x, y; cin >> x >> y;
            if (indexset[x].size() == 0) {
                continue;
            }
            int sts = indexset[x][0];
            for (int t : indexset[x]) {
                _union(t, sts);
            }
            indexset[x].clear();
            indexset[y].push_back(find(sts));
        }


    }
    for (int i = 0; i < N; i++) {
        if (indexset[i].size() == 0) continue;
        int sts = indexset[i][0];
        for (int t : indexset[i]) {
            _union(t, sts);
        }
        indexset[i].clear();
        arr[find(sts)] = i;
    }
    for (int i = 0; i < cnt; i++) {
        cout << arr[find(i)] << ' ';
    }


}