#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
     
    int n;
    long long num;
    vector<long long> v;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> num;
        v.push_back(num);
    }
    
    sort(v.begin(), v.end());
    
    int left=0, right=n-1, count=0;
    long long target;
    
    for (int i = 0; i < n; i++) {
        target = v[i];

        left = 0;                
        right = n-1;
        if (right >= n)
            right = n-1;
        
        while (left < right) {
            long long sum = v[left] + v[right];

            if (sum == target) {
                if (i != left && i != right) {
                    count++;
                    break;
                }
                else if( i == right)
                    right--;
                else if (i == left)
                    left++;
            }
            else if (sum < target)
                left++;
            else  {
                right--;
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}
