#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'

int main() {
    cin.tie(NULL)->ios::sync_with_stdio(false);
    
    int n;
    long long dp[31][31];
    
    for (int j = 0; j < 31; j++) {
        dp[0][j] = 1;
        dp[j][0] = 0;
    }
    
    for (int i = 1; i < 31; i++) {
        for (int j = 1; j < 31; j++) {
            if (i > j)
                dp[i][j] = 0;
            else
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
        }
    }
    
    while(1) {
        cin >> n;
        if (n == 0)
            break;
        cout << dp[n][n] << endl;
    }
    
    return 0;
}