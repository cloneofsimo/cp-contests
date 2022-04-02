#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> coincase[4][4][4];
int arr[110];

void cases(int ones, int twos, int threes) {
    set<pair<int, int>> cas;
    for (int one = 0; one <= ones; one++) {
        for (int two = 0; two <= twos; two++) {
            for (int three = 0; three <= threes; three++) {
                int cat = 0;
                for (int ro = 0; ro <= ones - one; ro++) {
                    for (int rt = 0; rt <= twos - two, two++) {
                        if (ro + rt * 2 % 3 == 0) {
                            cat = max(ro + rt * 2 / 3, cat);
                        }
                    }
                }
                cas.insert({ one + two * 2 + three * 3, (threes - three) + cat });
            }
        }
    }
    for (auto& c : cas) {
        coincase[ones][twos][threes].push_back({ c.first, c.second });
    }
}

void init() {
    for (int ones = 0; ones < 4; ones++) {
        for (int twos = 0; twos < 4; twos++) {
            for (int threes = 0; threes < 4; threes++) {
                cases(ones, twos, threes);
            }
        }
    }

}


int n;

int chk(int ones, int twos, int threes) {
    int gmaxt = 1000;
    for (int i = 0; i < n; i++) {
        int maxt = -1;
        for (auto& c : coincase[ones][twos][threes]) {
            if (arr[i] == c.first) {
                maxt = max(maxt, c.second);
            }
        }
        if (maxt == -1)
            return 0;
        gmaxt = min(gmaxt, maxt);
    }
    return gmaxt;
}


int main() {

    init();



    int T; cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int ans = 100000;
        for (int ones = 0; ones < 4; ones++) {
            for (int twos = 0; twos < 4; twos++) {
                for (int threes = 0; threes < 4; threes++) {
                    int gmaxt = chk(ones, twos, threes);
                    ans = min(ones + twos + threes + gmaxt, ans);
                }
            }
        }

        cout << ans << '\n';
    }

}