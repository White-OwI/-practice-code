#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
using ll = long long;

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

        map<ll, ll> last;
        ll l = 0;
        ll ans = 0;

        for (ll r = 0; r < n; ++r) {
            if (last.count(a[r]) && last[a[r]] >= l) {
                l = last[a[r]] + 1;
            }
            last[a[r]] = r;
            ans = max(ans, r - l + 1);
        }

        cout << ans << '\n';
    }
}