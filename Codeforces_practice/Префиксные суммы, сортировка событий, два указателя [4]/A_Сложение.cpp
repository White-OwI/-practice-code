#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, q;
    cin >> n >> q;

    vector<ll> diff(n + 2, 0);

    for (ll i = 0; i < q; ++i) {
        ll l, r, v;
        cin >> l >> r >> v;

        diff[l] += v;
        diff[r + 1] -= v;
    }

    vector<ll> ans(n + 1, 0);
    ll cur = 0;
    for (ll i = 1; i <= n; ++i) {
        cur += diff[i];
        ans[i] = cur;
    }

    for (ll i = 1; i <= n; ++i) {
        cout << ans[i] << (i == n ? '\n' : ' ');
    }
}