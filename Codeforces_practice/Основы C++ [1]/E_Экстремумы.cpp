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

    vector<ll> local_min, local_max;
    ll global_min_pos = 0, global_max_pos = 0;

    for (ll i = 0; i < n; ++i) {
        if (a[i] < a[global_min_pos]) global_min_pos = i;
        if (a[i] > a[global_max_pos]) global_max_pos = i;

        bool left_ok = (i == 0) || (a[i] != a[i - 1]);
        bool right_ok = (i == n - 1) || (a[i] != a[i + 1]);

        if (!left_ok || !right_ok) continue;

        bool is_min = true, is_max = true;

        if (i > 0) {
            if (a[i] > a[i - 1]) is_min = false;
            if (a[i] < a[i - 1]) is_max = false;
        }

        if (i < n - 1) {
            if (a[i] > a[i + 1]) is_min = false;
            if (a[i] < a[i + 1]) is_max = false;
        }

        if (is_min) local_min.push_back(i + 1);
        if (is_max) local_max.push_back(i + 1);
    }

    cout << local_min.size();
    for (ll pos : local_min) cout << ' ' << pos;
    cout << '\n';

    cout << local_max.size();
    for (ll pos : local_max) cout << ' ' << pos;
    cout << '\n';

    cout << global_min_pos + 1 << ' ' << global_max_pos + 1 << '\n';
}