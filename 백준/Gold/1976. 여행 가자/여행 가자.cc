#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;


vector<int> parent(201);


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

    int n, m, num;
    cin >> n >> m;
  
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> num;
            if (num == 1)
                merge(i, j);
        }
    }
    bool ans = true ;
    int p = 0;
    for (int i = 0; i < m; i++) {
        cin >> num;
        if (i == 0) p = find(num);
        else {
            if (p != find(num)) {
                ans = false;
                break;
            }
            else continue;
        }
    }
    
    cout << (ans ? "YES" : "NO")  << '\n';
        
    return 0;
}
