#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m, u, v;
    cin >> n >> m >> u >> v;

    vector<vector<ll>> g(n + 1);
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (ll i = 1; i <= n; ++i) {
        sort(all(g[i]));
    }

    vector<ll> dist(n + 1, -1);
    vector<ll> parent(n + 1, -1);
    queue<ll> q;

    dist[u] = 0;
    q.push(u);

    while (!q.empty()) {
        ll cur = q.front();
        q.pop();

        for (ll to : g[cur]) {
            if (dist[to] == -1) {
                dist[to] = dist[cur] + 1;
                parent[to] = cur;
                q.push(to);
            }
        }
    }

    if (dist[v] == -1) {
        cout << "-1\n";
        return 0;
    }

    vector<ll> path;
    ll cur = v;
    while (cur != -1) {
        path.push_back(cur);
        cur = parent[cur];
    }

    reverse(all(path));

    for (ll i = 0; i < (ll)path.size(); ++i) {
        cout << path[i] << (i + 1 == (ll)path.size() ? '\n' : ' ');
    }
}