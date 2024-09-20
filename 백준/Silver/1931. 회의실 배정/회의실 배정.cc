#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, start, end;
    pair<int, int> p;
    vector<pair<int, int>> v, rooms1, rooms2;
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> start >> end;
        p = make_pair(start, end);
        v.push_back(p);
    }
    sort(v.begin(), v.end(), compare);
    
//    for (int i = 0; i < n; i++)
//        cout << v[i].first << " " << v[i].second << endl;
        
//    cout << "----------------------------------" << endl;
    
    
    int sum = 1, endTime = v[0].second;
//    cout << v[0].first << " " << v[0].second << endl;
    for (int i = 1; i < n; i++) {
        int startTime = v[i].first;
        if (endTime > startTime) continue;
        
        sum++;
        endTime = v[i].second;
//        cout << v[i].first << " " << v[i].second << endl;
    }

    cout << sum << endl;
    return 0;
}
