#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll theights[300050];
int n;


int is_mday_possible(ll days, ll maxheight) {
    // try to water all plants in days.
    ll evendays = days / 2;
    ll odddays = days - evendays;
    ll totheights = 0, maxodddays = 0;

    for (int i = 0; i < n; i++) {
        maxodddays += (maxheight - theights[i]) % 2;
        totheights += (maxheight - theights[i]);
    }
    if ((maxodddays <= odddays) && (evendays * 2 + odddays >= totheights)) return 1;
    else return 0;
}


ll tryh(ll maxheight) {

    ll resheight = 0;
    for (int i = 0; i < n; i++) {
        resheight += maxheight - theights[i];
    }

    ll r = 3 * resheight + 1, l = 0;
    while (l < r) {
        ll mid = (l + r) / 2;
        if (is_mday_possible(mid, maxheight)) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }

    return r;
}



void testcase() {
    cin >> n;

    ll maxheights = 0;

    for (int i = 0; i < n; i++) {
        cin >> theights[i];
        maxheights = max(maxheights, theights[i]);
    }

    ll minans = min({ tryh(maxheights), tryh(maxheights + 1), tryh(maxheights + 2) });

    cout << minans << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    for (int _t = 0; _t < T; _t++) {

        testcase();
    }
}