#include <iostream>
using namespace std;
#define endl '\n'

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    long long x, y, z;
    cin >> x >> y;
    
    z = y * 100 / x;
    
    int low = 0, high = 1000000000;
    
    if(z >= 99){
        cout << "-1" << endl;
        return 0;
    }
    
    while(low <= high) {
        int mid = (low+high) / 2;
        int new_z = (y + mid) * 100 / (x + mid);
        
        if (new_z <= z)
            low = mid+1;
        else
            high = mid-1;
    }
    cout << low << endl;
    
    return 0;
}
