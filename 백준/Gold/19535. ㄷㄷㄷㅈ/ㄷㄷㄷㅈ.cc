#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'


int main() {
    cin.tie(NULL)->ios::sync_with_stdio(false);
    long long n, u, v;
    vector<vector<long long>> graph(300001);
    long long D=0, G=0;

    vector<pair<long long, long long>> p;

    cin >> n;
    
    for (long long i = 0; i < n-1; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        p.push_back(pair<long long, long long>(u, v));
    }
    
    for (long long i = 0; i < n-1; i++) {
        long long fi = p[i].first;
        long long se = p[i].second;
        D += (graph[fi].size()-1) * (graph[se].size()-1);
    }
    
    for (long long i = 1; i <= n; i++) {
        if (graph[i].size() >= 3) {
            long long size = graph[i].size();
            G += (size*(size-1)*(size-2))/6;
        }
    }
    
    if (G * 3 == D)
        cout << "DUDUDUNGA" << endl;
    else if (G * 3 < D)
        cout << 'D' << endl;
    else
        cout << 'G' << endl;
    return 0;
}
