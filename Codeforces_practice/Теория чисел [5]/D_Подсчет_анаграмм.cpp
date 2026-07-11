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

    string s;
    cin >> s;

    vector<ll> cnt(26, 0);
    for (char c : s) {
        cnt[c - 'a']++;
    }

    ll fact = 1;
    for (ll i = 2; i <= (ll)s.size(); ++i) {
        fact = (fact * i) % MOD;
    }

    ll denom = 1;
    for (ll i = 0; i < 26; ++i) {
        for (ll j = 2; j <= cnt[i]; ++j) {
            denom = (denom * j) % MOD;
        }
    }

    ll ans = fact * mod_pow(denom, MOD - 2) % MOD;
    cout << ans << '\n';
}