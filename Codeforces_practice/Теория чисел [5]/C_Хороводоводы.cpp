#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
using ll = long long;

const ll MOD = 1000000007LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;

    ll ans = 1;
    for (ll i = 2; i <= n - 1; ++i) {
        ans = (ans * i) % MOD;
    }

    ans = (ans * 500000004) % MOD;

    cout << ans << '\n';
}