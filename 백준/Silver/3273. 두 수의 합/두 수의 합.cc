#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, num, ans, m;
    vector<int> v;
    
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        v.push_back(num);
    }
    cin >> m;
    
    sort(v.begin(), v.end());
    
    int left = 0, right = n-1;
    int count = 0;
    
    while (left < right) {
        int sum = v[left] + v[right];
        if (sum == m) {
            count++;
            left++;
            right--;
        } else if (sum < m) {
            left++;
        } else {
            right--;
        }
    }
    
    cout << count << endl;
    return 0;
}
