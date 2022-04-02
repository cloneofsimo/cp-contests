#include <bits/stdc++.h>
using namespace std;

int boxs[105][105];
int n, m;

int touchs(int x, int y) {
    int endx = 0, endy = 0;
    while (boxs[x + endx][y] > 0) {
        endx += 1;
    }
    while (boxs[x][y + endy] > 0) {
        endy += 1;
    }
    //cout << "Endx: " << endx << " Endy: " << endy << endl;
    // everything in [x, x + endx) x [y, y + endy) should be 1
    int is_inside_1 = 1;
    for (int i = x; i < x + endx; i++) {
        for (int j = y; j < y + endy; j++) {
            if (boxs[i][j] != 1) {
                is_inside_1 = 0;
                break;
            }
        }
    }
    if (!is_inside_1) {
        return 1;
    }
    // everything on the boundary should be 0
    int is_boundary_0 = 1;
    for (int i = x; i < x + endx; i++) {
        if ((y - 1 >= 0 && boxs[i][y - 1] != 0) || (boxs[i][y + endy] != 0)) {
            is_boundary_0 = 0;
            break;
        }
    }
    for (int j = y; j < y + endy; j++) {
        if ((x - 1 >= 0 && boxs[x - 1][j] != 0) || (boxs[x + endx][j] != 0)) {
            is_boundary_0 = 0;
            break;
        }
    }
    if (!is_boundary_0) {
        return 1;
    }
    // clear inside
    for (int i = x; i < x + endx; i++) {
        for (int j = y; j < y + endy; j++) {
            boxs[i][j] = 0;
        }
    }
    return 0;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    while (T--) {
        memset(boxs, 0, sizeof(boxs));

        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            string S; cin >> S;
            for (int j = 0; j < m; j++) {
                boxs[i][j] = S[j] - '0';
            }
        }
        //cout << "DONE\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (boxs[i][j]) {
                    if (touchs(i, j)) {
                        cout << "NO\n";
                        goto NEXT;
                    };
                }

            }
        }
        cout << "YES\n";
    NEXT:
        0;
    }
}