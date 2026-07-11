#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
using ll = long long;

const ll MOD = 1000000007LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, k, m;
    cin >> n >> k >> m;

    vector<bool> danger(n + 1, false);
    for (ll i = 0; i < m; ++i) {
        ll x;
        cin >> x;
        danger[x] = true;
    }

    vector<ll> dp(n + 1, 0);
    vector<ll> pref(n + 1, 0);
    
    dp[0] = 1;
    pref[0] = 1;

    for (ll i = 1; i <= n; ++i) {
        if (danger[i]) {
            dp[i] = 0;
        } else {
            ll l = max(0LL, i - k);
            ll sum = pref[i - 1];
            if (l > 0) sum = (sum - pref[l - 1] + MOD) % MOD;
            dp[i] = sum;
        }
        pref[i] = (pref[i - 1] + dp[i]) % MOD;
    }

    cout << dp[n] << '\n';
}