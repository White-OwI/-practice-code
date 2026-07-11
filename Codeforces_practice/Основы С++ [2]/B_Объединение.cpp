#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        pq.push(x);
    }

    for (ll i = 0; i < n - 1; ++i) {
        ll a = pq.top(); pq.pop();
        ll b = pq.top(); pq.pop();
        if (a > b) swap(a, b);
        cout << a << ' ' << b << '\n';
        pq.push(a + b);
    }
}