#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void testcase() {
    int n, P; cin >> n >> P;
    vector<vector<int>> prdt(n, vector<int>(P));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < P; j++) {
            cin >> prdt[i][j];
        }
        sort(prdt[i].begin(), prdt[i].end());
    }

    ll prv_bottom = 0;
    ll prv_top = 0;

    ll prv_bottom_cost = 0;
    ll prv_top_cost = 0;

    for (ll i = 0; i < n; i++) {

        ll trcost = prdt[i][P - 1] - prdt[i][0];

        ll t2t = abs(prv_top - prdt[i][P - 1]) + prv_top_cost;
        ll t2b = abs(prv_top - prdt[i][0]) + prv_top_cost;
        ll b2t = abs(prv_bottom - prdt[i][P - 1]) + prv_bottom_cost;
        ll b2b = abs(prv_bottom - prdt[i][0]) + prv_bottom_cost;

        ll ttcost = t2b + trcost;
        ll tbcost = t2t + trcost;
        ll btcost = b2b + trcost;
        ll bbcost = b2t + trcost;

        ll top_tot = min(btcost, ttcost);
        ll bottom_tot = min(bbcost, tbcost);

        prv_top = prdt[i][P - 1];
        prv_top_cost = top_tot;

        prv_bottom = prdt[i][0];
        prv_bottom_cost = bottom_tot;
    }

    cout << min(prv_top_cost, prv_bottom_cost) << '\n';

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