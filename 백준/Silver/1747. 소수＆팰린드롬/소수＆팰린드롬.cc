#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, size = 2000000;
    cin >> n;
    
    int arr[2000001];
    
    for (int i = 2; i <= size; i++)
        arr[i] = i;
    
    for (int i = 2; i <= size; i++) {
        if (arr[i] == 0)
            continue;
        for (int j = 2 * i; j <= size; j += i)
            arr[j] = 0;
    }
    for (int i = n; i <= size; i++) {
        if (arr[i] != 0) {
            string s = to_string(arr[i]);
            string tmp = s;
            reverse(tmp.begin(), tmp.end());

            if (tmp == s) {
                cout << s << endl;
                break;
            }
        }
    }
    return 0;
}