#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <utility>
#include <tuple>
#include <stack>

using namespace std;
#define endl '\n'

struct Assignment {
    int isAssignment;
    int a;
    int t;
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, isAssignment, a, t;
    stack<Assignment> st;
    cin >> n;
    
    int ans = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> isAssignment;
        
        if (isAssignment == 0) { // 0일 때
            if(!st.empty()) st.top().t--;
        }
        else {
            cin >> a >> t; // 1일 때
            
            st.push({isAssignment, a, t});
            st.top().t--;
        }
       
        if (!st.empty() && st.top().t == 0) {
            ans += st.top().a;
            st.pop();
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
