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

    for (ll i = n; i >= 1; --i) {
        cout << i << (i == 1 ? '\n' : ' ');
    }
}