#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define endl '\n'

int main() {
    cin.tie(NULL)->ios::sync_with_stdio(false);
    int MOD = pow(10, 9) + 7, ans=0;
    string s;
    cin >> s;
    
    for (int i = 0, j = 1; i < s.length(); ++i, j = 2 * j % MOD) {
        if (s[i] == 'O')
            ans = (ans + j) % MOD;
    }

    cout << ans << endl;
    return 0;
}
