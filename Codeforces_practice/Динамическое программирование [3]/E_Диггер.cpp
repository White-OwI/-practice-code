#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> a(n, vector<ll>(m));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    vector<vector<ll>> dp(n, vector<ll>(m, 0));
    dp[0][0] = a[0][0];

    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            if (i == 0 && j == 0) continue;

            ll best = 0;
            if (i > 0) best = max(best, dp[i - 1][j]);
            if (j > 0) best = max(best, dp[i][j - 1]);
            if (i > 0 && j > 0) best = max(best, dp[i - 1][j - 1]);

            dp[i][j] = best + a[i][j];
        }
    }

    cout << dp[n - 1][m - 1] << '\n';
}