#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define endl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    priority_queue<int> q;
    
    int n, card, a, b, sum=0, result=0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> card;
        q.push(-card);
    }
    if (q.size() == 1) {
        cout << 0 << endl;
        return 0;
    }
    while(q.size() > 1) {
        
        a = -(q.top());
        q.pop();
//        cout << "a : " << a << endl;
        
        b = -(q.top());
        q.pop();
//        cout << "b : " << b << endl;
        
        sum = a + b;
//        cout << "sum : " << sum << endl;
        q.push(-sum);
        result += sum;
//        cout << "---------------" << endl << endl;
        
    }
    cout << result << endl;
    
    return 0;
}

