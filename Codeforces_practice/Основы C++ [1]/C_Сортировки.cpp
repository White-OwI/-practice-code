#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
using ll = long long;
using pll = array<ll, 2>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll T;
    cin >> T;

    while (T--) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (ll i = 0; i < n; ++i) {
            cin >> a[i];
        }

        ll ans = 0;
        for (ll i = 0; i < n; ++i) {
            for (ll j = i + 1; j < n; ++j) {
                if (a[i] > a[j]) {
                    ans++;
                }
            }
        }

        cout << ans << '\n';
    }
}