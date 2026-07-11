#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;

    vector<ll> dp(n + 1, 0);

    for (ll i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + i;

        if (i % 2 == 0) {
            dp[i] = min(dp[i], dp[i / 2] + i);
        }
        if (i % 3 == 0) {
            dp[i] = min(dp[i], dp[i / 3] + i);
        }
    }

    cout << dp[n] << '\n';
}