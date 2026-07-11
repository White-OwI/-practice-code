#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(all(a));

    ll ans = 0;
    ll r = 0;

    for (ll l = 0; l < n; ++l) {
        while (r < n && a[r] - a[l] <= k) {
            r++;
        }
        ll cnt = r - l - 1;
        ans += cnt * (cnt - 1) / 2;
    }

    cout << ans << '\n';
}