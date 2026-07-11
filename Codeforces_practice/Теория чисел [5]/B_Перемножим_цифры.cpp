#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        if (n == 0) {
            cout << "10\n";
            continue;
        }

        if (n == 1) {
            cout << "1\n";
            continue;
        }

        vector<ll> digits;

        for (ll d = 9; d >= 2; --d) {
            while (n % d == 0) {
                digits.push_back(d);
                n /= d;
            }
        }

        if (n > 1) {
            cout << "-1\n";
            continue;
        }

        sort(all(digits));

        for (ll d : digits) {
            cout << d;
        }
        cout << '\n';
    }
}