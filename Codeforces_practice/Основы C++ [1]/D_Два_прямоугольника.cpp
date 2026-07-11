#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
using ll = long long;
using pll = array<ll, 2>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll x1, y1, x2, y2;
    ll x3, y3, x4, y4;

    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    ll left1 = min(x1, x2);
    ll right1 = max(x1, x2);
    ll bottom1 = min(y1, y2);
    ll top1 = max(y1, y2);

    ll left2 = min(x3, x4);
    ll right2 = max(x3, x4);
    ll bottom2 = min(y3, y4);
    ll top2 = max(y3, y4);

    ll area1 = (right1 - left1) * (top1 - bottom1);
    ll area2 = (right2 - left2) * (top2 - bottom2);

    ll overlap_left = max(left1, left2);
    ll overlap_right = min(right1, right2);
    ll overlap_bottom = max(bottom1, bottom2);
    ll overlap_top = min(top1, top2);

    ll overlap_area = 0;
    if (overlap_left < overlap_right && overlap_bottom < overlap_top) {
        overlap_area = (overlap_right - overlap_left) * (overlap_top - overlap_bottom);
    }

    cout << area1 + area2 - overlap_area << '\n';
}