#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'

int binary_search(vector<int> v, int size, int target) {
    int low = 0, high = size-1;
    while(1) {
        int mid = (low + high) / 2;
        if (low > high)
            return 0;
        if (target == v[mid])
            return 1;
        else if (target > v[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
     
    int n, m, target;
    vector<int> v, money;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> m;
        money.push_back(m);
    }
    
    sort(money.begin(), money.end());
    
    int num = 0, end = money[n-1];

    while (1) {
        if (end < num)
            break;
        v.push_back(num);
        num++;
    }
    
    sort(v.begin(), v.end());

    int low = 0, high = v.size()-1, sum = 0, ans;
    
    cin >> target;
    
    // 모든 배열의 값이 다 같을 떄
    if (v.size() == 1) {
        ans = target / n;
        
    // 배열의 값이 하나라도 다를 때
    } else {
        while(1) {
            int mid = (low + high) / 2;
            if (low > high) {
                ans = v[mid];
                break;
            }
    //        cout << "v[mid] : " << v[mid] << endl;
            
            for (int i = 0; i < n; i++) {
                if (v[mid] > money[i])
                    sum += money[i];
                else
                    sum += v[mid];
            }
            if (sum == target) {
                ans = v[mid];
                break;
            }
            if (sum > target)
                high = mid - 1;
            else
                low = mid + 1;
            
            sum = 0;
    //        cout << "low : " << v[low] << ", high : " << v[high] << endl;
    //        cout << "--------------------" << endl;
        }
    }
    
    
    
        
    cout << ans << endl;
    return 0;
}
