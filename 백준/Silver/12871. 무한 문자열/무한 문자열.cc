#include <iostream>
#include <string>
using namespace std;
#define endl '\n'

long long gcd(long long x, long long y) {
    if (!y)
        return x;
    else
        return gcd(y, x%y);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    string s, t, fs, ft;
    cin >> s;
    cin >> t;
    
    int lcm = t.size() * s.size() / gcd(t.size(), s.size());

    string ans = "";
    for (int i = 0; i < lcm / s.size() ; i++) {
        fs += s;
    }
    
    for (int i = 0; i < lcm / t.size() ; i++) {
        ft += t;
    }

    cout << (fs == ft ? 1 : 0) << endl;
    
    return 0;
}
