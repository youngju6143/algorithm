#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long n, k;
    cin >> n;
    cin >> k;
    long long low = 1, high = n*n, sum=0;
    
    while (low <= high) {
//        cout << "low : " << low << ", high : " << high << endl;
        long long mid = (low + high) / 2;
//        cout << "mid : " << mid << endl;

        for (int i = 1; i <= n; i++) {
            sum += min(mid/i, n);
        }
        if (k > sum)
            low = mid + 1;
        else
            high = mid - 1;
        
        sum = 0;
//        cout << "--------------" << endl;
    }
    
    cout << low << endl;
    
    return 0;
}
