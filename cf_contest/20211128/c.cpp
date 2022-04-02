#include <bits/stdc++.h>
using namespace std;
#define N 1000010
using ll = long long;

int iscomp[N];
ll curprimecnt[N], prvprimecnt[N], hadprime[N];

void init_primes() {
    for (int i = 2; i < N; i++) {
        iscomp[i] = 0;
    }
    for (int i = 2; i < N; i++) {
        if (iscomp[i] == 0) {
            for (int j = i + i; j < N; j += i) {
                iscomp[j] = 1;
            }
        }
    }
}



int main() {
    init_primes();
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n, e; cin >> n >> e;
        ll ans = 0;
        for (int i = 0; i < e; i++) {
            curprimecnt[i] = 0;
            prvprimecnt[i] = 0;
            hadprime[i] = 0;
        }

        for (int i = 0; i < n; i++) {
            int ord = i % e;
            int x; cin >> x;
            if (x == 1) {
                curprimecnt[ord]++;
            }
            else if (iscomp[x] == 0) {
                if (hadprime[ord])
                    ans += (curprimecnt[ord] + 1) * (prvprimecnt[ord] + 1) - 1;
                hadprime[ord] = 1;
                prvprimecnt[ord] = curprimecnt[ord];
                curprimecnt[ord] = 0;

            }
            else {
                if (hadprime[ord])
                    ans += (curprimecnt[ord] + 1) * (prvprimecnt[ord] + 1) - 1;
                hadprime[ord] = 0;
                prvprimecnt[ord] = 0;
                curprimecnt[ord] = 0;
            }
        }
        for (int ord = 0; ord < e; ord++) {
            if (hadprime[ord])
                ans += (curprimecnt[ord] + 1) * (prvprimecnt[ord] + 1) - 1;
        }

        cout << ans << '\n';
    }

}