#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n, index=0, revCnt=0;
        string p, tmp, arr;
        deque<int> d;
        bool isErr = false, isRev = false;
        
        cin >> p;
        cin >> n;
        cin >> arr;
        
        for (int j = 0; j < arr.length(); j++) {
            if (arr[j] == '[')
                continue;
            else if (isdigit(arr[j]))
                tmp += arr[j];
            else if (arr[j] == ']' || arr[j] == ',') {
                if (tmp.length()) {
                    d.push_back(stoi(tmp));
                    tmp.clear();
                }
            }
        }
        
        for (int j = index; j < p.length(); j++) {
            if (p[j] == 'R') {
                revCnt++;
            }
            else if (p[j] == 'D') {
                if (d.empty()) {
                    isErr = true;
                    break;
                }
                if (revCnt % 2 == 1)
                    d.pop_back();
                else
                    d.pop_front();
            }
            if (isErr)
                break;
        }
        
        if (revCnt % 2 == 1)
            isRev = true;
 
        if (isErr)
            cout << "error" << endl;
        else {
            cout << '[';
            if (isRev)
                for (int j = d.size()-1; j != -1; j--) {
                    cout << d[j];
                    if (j == 0)
                        break;
                    cout << ',';
                }
            else {
                for (int j = 0; j < d.size(); j++) {
                    cout << d[j];
                    if (j == d.size()-1)
                        break;
                    cout << ',';
                }
            }
            cout << ']' << endl;
        }
    }
    return 0;
}