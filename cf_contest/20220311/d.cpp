#include <bits/stdc++.h>
using namespace std;
using ll = long long;



const ll INF = 1000000000;

void dijkstra(ll s, vector<ll>& d, vector<ll>& p, vector<vector<pair<ll, ll>>>& adj) {
    ll n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    using pii = pair<ll, ll>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({ 0, s });
    while (!q.empty()) {
        ll v = q.top().second;
        ll d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;

        for (auto edge : adj[v]) {
            ll to = edge.first;
            ll len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({ d[to], to });
            }
        }
    }
}

const ll N = 500050;

ll dx[4] = { 1, 0, -1, 0 };
ll dy[4] = { 0, 1, 0, -1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n; cin >> n;
    vector<ll> qry;

    set<ll> ori, every;
    for (ll i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;
        ll pos = x * N + y;
        ori.insert(pos);
        qry.push_back(pos);
        for (ll j = 0; j < 4; j++) {
            ll nx = x + dx[j];
            ll ny = y + dy[j];
            ll npos = nx * N + ny;
            every.insert(npos);
        }
        every.insert(pos);
    }

    map<ll, ll> pos2idx;
    map<ll, ll> idx2pos;
    ll cnt = 1;
    vector<vector<pair<ll, ll>>> adj(every.size() + 1);

    for (ll pos : every) {
        idx2pos[cnt] = pos;
        pos2idx[pos] = cnt++;
    }
    for (ll pos : every) {
        for (ll j = 0; j < 4; j++) {
            ll nx = pos / N + dx[j];
            ll ny = pos % N + dy[j];

            ll npos = nx * N + ny;
            if (every.find(npos) != every.end()) {
                adj[pos2idx[pos]].push_back({ pos2idx[npos], 1 });
            }
        }
    }
    set<ll> outsiders;
    for (ll pos : every) {
        if (ori.find(pos) == ori.end()) {
            outsiders.insert(pos);
        }
    }

    // connect outsiders to 0.
    for (ll pos : outsiders) {
        adj[0].push_back({ pos2idx[pos], 1 });
    }

    vector<ll> d, p;
    dijkstra(0, d, p, adj);
    for (ll i = 0; i < qry.size(); i++) {
        ll pos = qry[i];
        for (ll v = pos2idx[pos]; v != 0; v = p[v]) {
            if (d[v] == 1) {
                ll x = idx2pos[v] / N;
                ll y = idx2pos[v] % N;
                cout << x << ' ' << y << '\n';
            }
        }
    }
}