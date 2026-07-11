#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
using ll = long long;

const ll MOD = 1000000007LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll l, r;
    cin >> l >> r;

    vector<ll> dp(r + 1, 0);
    dp[1] = 1;

    for (ll i = 1; i <= r; ++i) {
        if (dp[i] == 0) continue;

        for (ll j = 2 * i; j <= r; j += i) {
            dp[j] = (dp[j] + dp[i]) % MOD;
        }
    }

    ll ans = 0;
    for (ll i = l; i <= r; ++i) {
        ans = (ans + dp[i]) % MOD;
    }

    cout << ans << '\n';
}