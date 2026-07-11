#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) cin >> a[i];

    sort(all(a));
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        for (ll j = i + 1; j < n; ++j) {
            ll sum = a[i] + a[j];
            ll k = lower_bound(a.begin() + j + 1, a.end(), sum) - a.begin();
            ans += k - j - 1;
        }
    }
    cout << ans << '\n';
}