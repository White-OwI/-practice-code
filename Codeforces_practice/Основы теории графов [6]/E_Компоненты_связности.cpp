#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
using ll = long long;

vector<vector<ll>> g;
vector<bool> used;

void dfs(ll v) {
    used[v] = true;

    for (ll to : g[v]) {
        if (!used[to]) {
            dfs(to);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    g.assign(n + 1, {});
    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    used.assign(n + 1, false);
    ll ans = 0;

    for (ll i = 1; i <= n; ++i) {
        if (!used[i]) {
            ans++;
            dfs(i);
        }
    }

    cout << ans << '\n';
}