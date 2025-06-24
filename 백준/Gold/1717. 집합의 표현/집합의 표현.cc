#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;


vector<int> parent(1000001);


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

    int n, m, num, a, b;
    cin >> n >> m;
  
    for (int i = 0; i < m; i++) {
        cin >> num >> a >> b;
        
        if (num == 0)
            merge(a, b);
        else
            find(a) == find(b) ? cout << "YES" << '\n' : cout << "NO" << '\n';
    }
    return 0;
}
