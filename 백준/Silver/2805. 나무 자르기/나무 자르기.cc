#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long n, m, num;
    vector<long long> v;
    cin >> n >> m;
    
    for (long long i = 0; i < n; i++) {
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    long long size = v.size();
    long long high = v[size-1], low = 1, mid=0;
    while(1) {
        long long cnt = 0;
        if (low > high)
            break;
        mid = (low + high) / 2;
        for (long long i = 0; i < size; i++) {
            if (v[i] > mid)
                cnt += v[i] - mid;
        }
        if (cnt < m)
            high = mid - 1;
        else if (cnt >= m)
            low = mid + 1;
    }
    cout << low-1 << endl;
    return 0;
}