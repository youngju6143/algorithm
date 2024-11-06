#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, k, money, cnt=0;
    vector<int> v;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> money;
        v.push_back(money);
    }
    
    int i = v.size()-1;
    while(k != 0) {
        if (k / v[i] == 0) {
            i--;
        }
        else {
            int q;
            q = k / v[i];
            k -= v[i] * q;
            cnt += q;
        }
    }
    cout << cnt << endl;
    
    return 0;
}