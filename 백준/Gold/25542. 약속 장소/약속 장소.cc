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
#include <cmath>
#include <map>

using namespace std;
#define endl '\n'

vector<pair<char, int>> alphabets;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n, l;
    string s, ans;
    vector<string> v;
    cin >> n >> l;
    
   
    for (int i = 0; i < n; i++) {
        cin >> s;
        v.push_back(s);
    }
    
    string base = v[0];
    
    for (int j = 0; j < l; j++) {
        string candidate;
        for (char ch = 'A'; ch <= 'Z'; ch++) {
            candidate = base;
            candidate[j] = ch;
            
            // 배열 내 단어들과 베이스 단어랑 한 글자씩 비교
            bool isValid = true;

            for (int k = 1; k < v.size(); k++){
                int cnt = 0;
                for (int m = 0; m < l; m++)
                    if (v[k][m] != candidate[m]) cnt++;


                // 다른 문자가 2개 이상이면 무조건 CALL FRIEND 호출
                if (cnt > 1) {
                    isValid = false;
                    continue;
                }
                cnt = 0;
            }
            // isValid = true -> 단어 추측 가능
            if (isValid) {
                cout << candidate << endl;
                return 0;
            }
        }
    }
    
    cout << "CALL FRIEND" << endl;
    return 0;
}
