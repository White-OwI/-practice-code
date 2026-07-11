#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m, k;
    cin >> n >> m >> k;

    vector<vector<ll>> g(n + 1);
    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<ll> dist(n + 1, -1);
    queue<ll> q;

    dist[k] = 0;
    q.push(k);

    while (!q.empty()) {
        ll v = q.front();
        q.pop();

        for (ll to : g[v]) {
            if (dist[to] == -1) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }

    for (ll i = 1; i <= n; ++i) {
        cout << dist[i] << (i == n ? '\n' : ' ');
    }
}