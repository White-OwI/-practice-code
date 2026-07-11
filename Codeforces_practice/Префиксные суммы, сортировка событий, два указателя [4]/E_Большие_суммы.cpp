#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
using ll = long long;

const ll MOD = 1000000007LL;

ll mod_pow(ll base, ll exp) {
    ll res = 1;
    while (exp) {
        if (exp & 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;

    ll sum = 0;
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        sum = (sum + x % MOD + MOD) % MOD;
    }

    ll ans = sum * mod_pow(2, n - 1) % MOD;
    cout << ans << '\n';
}