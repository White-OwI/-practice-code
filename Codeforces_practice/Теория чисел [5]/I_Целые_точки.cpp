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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;

    while (n--) {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        ll dx = abs(x2 - x1);
        ll dy = abs(y2 - y1);

        ll ans = gcd(dx, dy) + 1;
        cout << ans << '\n';
    }
}