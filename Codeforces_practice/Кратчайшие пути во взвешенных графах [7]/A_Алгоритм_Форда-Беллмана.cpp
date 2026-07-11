#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
using ll = long long;

struct Edge {
    ll u, v, w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m, s;
    cin >> n >> m >> s;

    vector<Edge> edges(m);
    for (ll i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    const ll INF = 4e18;
    vector<ll> dist(n + 1, INF);
    dist[s] = 0;

    for (ll i = 0; i < n - 1; ++i) {
        bool changed = false;
        for (auto e : edges) {
            if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
                changed = true;
            }
        }
        if (!changed) break;
    }

    for (auto e : edges) {
        if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
            cout << "Negative cycle\n";
            return 0;
        }
    }

    for (ll i = 1; i <= n; ++i) {
        if (dist[i] == INF) {
            cout << "inf";
        } else {
            cout << dist[i];
        }
        cout << (i == n ? '\n' : ' ');
    }
}