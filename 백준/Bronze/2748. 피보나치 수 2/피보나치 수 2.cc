#include <iostream>
using namespace std;

int main() {
    int n;
    long long a[91] = {0,};
    a[0] = 0;
    a[1] = 1;
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        a[i+2] = a[i+1] + a[i];
    }
    
    cout << a[n] << endl;
    
    return 0;
}
