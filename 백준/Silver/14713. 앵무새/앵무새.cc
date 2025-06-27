#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <utility>
#include <tuple>
#include <stack>
#include <queue>
#include <sstream>


using namespace std;
#define endl '\n'



int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    vector<queue<string>> v;
    bool isPossible = false;
    int n, word_cnt=0, cnt=0;
    cin >> n;
    cin.ignore();

    string s, word;
    
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        stringstream ss(s);
        queue<string> q;
        
        while (ss >> word) {
            q.push(word);
            word_cnt++;
        }
        v.push_back(q);
    }
    

    getline(cin, s);
    stringstream ss (s);
    stack<string> st;
    queue<string> sentence;
    
    
    while (ss >> word) {
        sentence.push(word);
    }
    
    while(1) {
        bool isFound = false;

        if (cnt >= word_cnt && !v.empty()) {
            isPossible = false;
            break;
        }
        
        if (sentence.empty() && v.empty()) {
            isPossible = true;
            break;
        }
        
        if (sentence.empty() && !v.empty()) {
            isPossible = false;
            break;
        }
        
        for (int i = 0; i < v.size(); i++) {
            if (v[i].front() == sentence.front()) {
                isFound = true;
                v[i].pop();
                sentence.pop();
                
                if (v[i].empty())
                    v.erase(v.begin() + i);
                break;
            }
        }
        
        if (!isFound) {
            isPossible = false;
            break;
        }
        
        cnt++;
    }
    
    cout << (isPossible ? "Possible" : "Impossible") << endl;
    
    return 0;
}
