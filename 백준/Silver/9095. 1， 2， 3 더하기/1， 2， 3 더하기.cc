#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'

int main() {
    cin.tie(NULL)->ios::sync_with_stdio(false);
    
    int t, n;
    cin >> t;
    int dp[11];
    
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    
    for (int i = 4; i < 11; i++)
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    
    for (int i = 0; i < t; i++) {
        cin >> n;
        cout << dp[n] << endl;
    }
    
    return 0;
}
