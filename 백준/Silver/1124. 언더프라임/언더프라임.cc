#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b, sum=0;
    int arr[100001];
    vector<int> prime;
    cin >> a >> b;

    for (int i = 2; i <= 100000; i++)
        arr[i] = i;

    for (int i = 2; i <= b; i++) {
        if (arr[i] == 0)
            continue;
        prime.push_back(arr[i]);
        for (int j = 2 * i; j <= b; j += i)
            arr[j] = 0;
    }

    for (int i = a; i <= b; i++) {
        int cnt = 0, tmp = i;
        for (int j = 0; j < prime.size(); j++) {
            while(tmp % prime[j] == 0){
                tmp = tmp / prime[j];
                cnt++;
            }
            if (tmp == 1)
                break;
        }
        if (arr[cnt] == cnt)
            sum++;
    }
    cout << sum << endl;
    return 0;
}