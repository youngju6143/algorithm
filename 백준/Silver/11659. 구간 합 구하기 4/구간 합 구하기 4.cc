#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, x, y, num, sum=0;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> num;
        sum += num;
        arr[i] = sum;
    }
   
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        if (x == 1)
            cout << arr[y-1] << endl;
        else
            cout << arr[y-1] - arr[x-2] << endl;
    }
    
    return 0;
}