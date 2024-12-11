#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'

int main() {
    cin.tie(NULL)->ios::sync_with_stdio(false);
    
    vector<int> v;
    int n, m, color;
    
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> color;
        v.push_back(color);
    }
    sort(v.begin(), v.end());
    
    int low = 1, high = v[m-1];
    int min=1000000001;
    
    while(1) {
        int child=0;
        int mid = (low + high) / 2;
        if (low > high)
            break;
        for (int i = 0; i < m; i++) {
            if (v[i] % mid == 0)
                child += v[i] / mid;
            else
                child += v[i] / mid + 1;
        }
//        cout << "mid : " << mid << ", child : " << child << endl;
        if (child > n)
            low = mid+1;
        else {
//            cout << "min : " << min << ", mid : " << mid << endl;
            if (min > mid)
                min = mid;
            high = mid-1;
        }
    }
    cout << min << endl;
    
    return 0;
}