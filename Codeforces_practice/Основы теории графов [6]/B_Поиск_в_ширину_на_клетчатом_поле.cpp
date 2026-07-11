#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (ll i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    ll x, y;
    cin >> x >> y;
    --x; --y;

    vector<vector<ll>> dist(n, vector<ll>(m, -1));
    queue<pair<ll, ll>> q;

    dist[x][y] = 0;
    q.push({x, y});

    ll dx[] = {-1, 1, 0, 0};
    ll dy[] = {0, 0, -1, 1};

    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();

        for (ll i = 0; i < 4; ++i) {
            ll nx = cx + dx[i];
            ll ny = cy + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                grid[nx][ny] != '#' && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[cx][cy] + 1;
                q.push({nx, ny});
            }
        }
    }

    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            cout << dist[i][j] << (j + 1 == m ? '\n' : ' ');
        }
    }
}