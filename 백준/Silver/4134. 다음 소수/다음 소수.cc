#include <iostream>
#include <cmath>
using namespace std;
#define endl '\n'

bool is_prime(long long n) {
    if (n <= 1) return false;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;
    
    long long n;
    
    for (long long i = 0; i < t; i++) {
        cin >> n;
        
        while(1) {
            if (is_prime(n)) {
                cout << n << endl;
                break;
            }
            n++;
        }
    }

    return 0;
}
