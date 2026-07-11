#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;

    priority_queue<ll> max_heap;
    priority_queue<ll, vector<ll>, greater<ll>> min_heap;

    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;

        if (max_heap.empty() || x <= max_heap.top()) {
            max_heap.push(x);
        } else {
            min_heap.push(x);
        }

        if (max_heap.size() > min_heap.size() + 1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        } else if (min_heap.size() > max_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }

        cout << max_heap.top() << '\n';
    }
}