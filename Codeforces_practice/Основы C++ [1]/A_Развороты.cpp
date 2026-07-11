#include <bits/stdc++.h>
using namespace std;
 
#define all(x) x.begin(), x.end()
using ll = long long;
using pll = array<ll, 2>;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
 
    ll l, r;
    while (cin >> l >> r) {
        if (l == 0 && r == 0) break;
        --l; --r;
        reverse(a.begin() + l, a.begin() + r + 1);
    }
 
    for (ll i = 0; i < n; ++i) {
        cout << a[i] << (i + 1 == n ? '\n' : ' ');
    }
}