#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, omega;
    cin >> n >> omega;
    vector<pair<ll, ll>> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    sort(all(a));

    vector<ll> order;
    ll cur = omega;
    ll idx = 0;

    while (idx < n) {
        if (cur > a[idx].first) {
            cur += a[idx].first;
            order.push_back(a[idx].second);
            idx++;
        } else {
            bool found = false;
            for (ll i = idx; i < n; ++i) {
                if (cur > a[i].first) {
                    cur += a[i].first;
                    order.push_back(a[i].second);
                    idx = i + 1;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << "YES\n";
    for (ll i = 0; i < n; ++i) {
        cout << order[i] << (i + 1 == n ? '\n' : ' ');
    }
}