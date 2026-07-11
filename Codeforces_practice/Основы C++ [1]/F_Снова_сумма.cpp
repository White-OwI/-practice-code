#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
using ll = long long;
using pll = array<ll, 2>;

string add(string a, string b) {
    string r;
    int carry = 0;
    int i = (int)a.size() - 1;
    int j = (int)b.size() - 1;
    
    while (i >= 0 || j >= 0 || carry) {
        if (i >= 0) carry += a[i--] - '0';
        if (j >= 0) carry += b[j--] - '0';
        r += char('0' + carry % 10);
        carry /= 10;
    }
    
    reverse(all(r));
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    string int_part = "0";
    string frac_part = "";
    
    while (cin >> s) {
        size_t dot = s.find('.');
        string a = s.substr(0, dot);
        string b = s.substr(dot + 1);
        
        while (b.size() < 15) b += '0';
        b = b.substr(0, 15);
        
        if (int_part == "0" && frac_part.empty()) {
            int_part = a;
            frac_part = b;
            continue;
        }
        
        string new_frac = add(frac_part, b);
        string carry = "0";
        
        if (new_frac.size() > 15) {
            carry = new_frac.substr(0, new_frac.size() - 15);
            new_frac = new_frac.substr(new_frac.size() - 15);
        }
        
        int_part = add(add(int_part, a), carry);
        frac_part = new_frac;
    }
    
    while (int_part.size() > 1 && int_part[0] == '0') {
        int_part.erase(int_part.begin());
    }
    
    cout << int_part << '.' << frac_part << '\n';
}