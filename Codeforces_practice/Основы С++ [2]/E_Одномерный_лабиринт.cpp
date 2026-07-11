#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll> d(n);
    for (ll i = 0; i < n; ++i) cin >> d[i];

    sort(all(d));
    ll q;
    cin >> q;
    while (q--) {
        ll s, f;
        cin >> s >> f;
        if (s > f) swap(s, f);
        cout << upper_bound(all(d), f) - lower_bound(all(d), s) << '\n';
    }
}