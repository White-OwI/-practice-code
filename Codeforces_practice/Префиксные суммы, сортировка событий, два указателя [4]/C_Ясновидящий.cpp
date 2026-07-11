#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll> a(n + 1, 0);
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<ll> pref(n + 1, 0);
    for (ll i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1] + a[i];
    }

    ll buy = -1, sell = -1;
    ll max_profit = 0;
    ll min_price = pref[0];
    ll min_pos = 0;

    for (ll i = 1; i <= n; ++i) {
        if (pref[i] - min_price > max_profit) {
            max_profit = pref[i] - min_price;
            buy = min_pos + 1;
            sell = i + 1;
        }
        if (pref[i] < min_price) {
            min_price = pref[i];
            min_pos = i;
        }
    }

    if (max_profit <= 0) {
        cout << "-1 -1\n";
    } else {
        cout << buy << ' ' << sell << '\n';
    }
}