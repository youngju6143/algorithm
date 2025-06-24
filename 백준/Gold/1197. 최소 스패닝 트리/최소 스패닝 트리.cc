#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;


vector<int> parent(10001);

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    
    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    iota(parent.begin(), parent.end(), 0);
    
    vector<vector<int>> vec;

    int v, e, a, b, w;
    int ans = 0, cnt = 0;
    
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        cin >> a >> b >> w;
        vec.push_back({w, a, b});
    }
    
    sort(vec.begin(), vec.end());
    
    for (int i = 0; i < vec.size(); i++) {
        w = vec[i][0];
        a = vec[i][1];
        b = vec[i][2];
        if (find(a) != find(b)) {
            merge(a, b);
            cnt++;
            ans += w;
        }
        
        if (cnt == v-1)
            break;
    }
    
    cout << ans << '\n';
        
    return 0;
}
