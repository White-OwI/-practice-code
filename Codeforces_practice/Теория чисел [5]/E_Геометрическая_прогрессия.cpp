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

    ll T;
    cin >> T;

    while (T--) {
        ll b1, q, n;
        cin >> b1 >> q >> n;

        if (n == 0) {
            cout << "0\n";
            continue;
        }

        if (q == 1) {
            cout << (b1 % MOD) * (n % MOD) % MOD << '\n';
            continue;
        }

        ll numerator = (mod_pow(q, n) - 1 + MOD) % MOD;
        ll denominator = (q - 1 + MOD) % MOD;
        ll ans = (b1 % MOD) * numerator % MOD * mod_pow(denominator, MOD - 2) % MOD;

        cout << ans << '\n';
    }
}