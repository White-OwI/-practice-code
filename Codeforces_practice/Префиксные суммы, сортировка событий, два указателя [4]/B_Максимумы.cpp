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
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll ans = 0;

    for (ll i = 0; i < n; ++i) {
        ll l = i - 1;
        while (l >= 0 && a[l] < a[i]) {
            l--;
        }

        ll r = i + 1;
        while (r < n && a[r] <= a[i]) {
            r++;
        }

        ll left_count = i - l;
        ll right_count = r - i;
        ans += a[i] * left_count * right_count;
    }

    cout << ans << '\n';
}