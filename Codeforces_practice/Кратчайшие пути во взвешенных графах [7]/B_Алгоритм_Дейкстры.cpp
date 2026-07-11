#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
using ll = long long;

struct Edge {
    ll to, w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    vector<vector<Edge>> g(n + 1);
    for (ll i = 0; i < m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    const ll INF = 4e18;
    vector<ll> dist(n + 1, INF);
    vector<ll> parent(n + 1, -1);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();

        if (d != dist[v]) continue;

        for (auto e : g[v]) {
            if (dist[v] + e.w < dist[e.to]) {
                dist[e.to] = dist[v] + e.w;
                parent[e.to] = v;
                pq.push({dist[e.to], e.to});
            }
        }
    }

    if (dist[n] == INF) {
        cout << "-1\n";
        return 0;
    }

    vector<ll> path;
    ll cur = n;
    while (cur != -1) {
        path.push_back(cur);
        cur = parent[cur];
    }

    reverse(all(path));

    for (ll i = 0; i < (ll)path.size(); ++i) {
        cout << path[i] << (i + 1 == (ll)path.size() ? '\n' : ' ');
    }
}