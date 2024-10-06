#include <iostream>
using namespace std;
#define endl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, sum=0;
    cin >> n;
    while(n >= 0) {
        if (n % 5 == 0) {
            sum += n / 5;
            cout << sum << endl;
            return 0;
        }
        else {
            n -= 3;
            sum++;
        }
    }
    cout << -1 << endl;
    
}
