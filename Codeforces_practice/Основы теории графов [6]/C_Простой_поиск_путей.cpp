#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
using ll = long long;

vector<vector<ll>> g;
vector<ll> parent;
vector<bool> used;

bool dfs(ll v, ll target) {
    used[v] = true;

    if (v == target) {
        return true;
    }

    for (ll to : g[v]) {
        if (!used[to]) {
            parent[to] = v;
            if (dfs(to, target)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m, u, v;
    cin >> n >> m >> u >> v;

    g.assign(n + 1, {});
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    used.assign(n + 1, false);
    parent.assign(n + 1, -1);

    if (!dfs(u, v)) {
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