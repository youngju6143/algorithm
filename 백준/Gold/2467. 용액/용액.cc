#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    vector<int> v;
    int n, l;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> l;
        v.push_back(l);
    }
    
    sort(v.begin(), v.end());
    
    int low = 0, high = v.size() - 1;
    int min = 2000000001;
    int lowValue = v[low], highValue = v[high];

    while (low < high) {

        int tmp = v[low] + v[high];
        
        if (tmp == 0) {
            lowValue = v[low];
            highValue = v[high];
            break;
        }
        
        if (abs(tmp) < min) {
            min = abs(v[low] + v[high]);
            lowValue = v[low];
            highValue = v[high];
        }
    
        if (tmp < 0)
            low++;
        else
            high--;
    }
    
    cout << lowValue << " " << highValue << endl;
}
