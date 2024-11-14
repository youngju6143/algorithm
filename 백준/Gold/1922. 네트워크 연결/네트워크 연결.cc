#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define endl '\n'

int parent[1001];


int compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    return a.second < b.second;
}

int find(int v) {
    if (parent[v] != v)
        parent[v] = find(parent[v]);
    return parent[v];
}

int main() {
    cin.tie(NULL)->ios::sync_with_stdio(false);
    
    int n, m, a, b, c, total=0;
    
    vector<pair<pair<int, int>, int>> v;
    
    pair<pair<int, int>, int> edge;
    pair<int, int> p;
    
    cin >> n;
    cin >> m;
    
    
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        p.first = a;
        p.second = b;
        
        edge.first = p;
        edge.second = c;
        v.push_back(edge);
    }
    
    sort(v.begin(), v.end(), compare);
    
    
    for (int i = 0; i < m; i++) {
        int firstNode = v[i].first.first;
        int secondNode = v[i].first.second;
        
        int parent_a = find(firstNode);
        int parent_b = find(secondNode);

        if (parent_a == parent_b)
            continue;
        else {
            parent_a < parent_b ? parent[parent_b] = parent_a : parent[parent_a] = parent_b;
            total += v[i].second;
        }
    }
    cout << total << endl;
    
    return 0;
}