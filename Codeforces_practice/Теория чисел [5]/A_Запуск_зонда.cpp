#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
using ll = long long;

ll gcd(ll a, ll b) {
    while (b) {
        ll t = a % b;
        a = b;
        b = t;
    }
    return a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;

    ll ans = 1;
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        ans = lcm(ans, x);
    }

    cout << ans << '\n';
}