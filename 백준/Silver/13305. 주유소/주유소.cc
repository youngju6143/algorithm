#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    
    int n;
    long long dist[100000], cost[100000], min_cost, total_cost=0;
    
    cin >> n;
    
    for(int i = 1; i < n; i++){
        cin >> dist[i];
    }
    
    for(int i = 0; i < n; i++){
        cin >> cost[i];
    }
    
    min_cost = cost[0];
    
    for (int i = 1; i < n; i++) {
        total_cost += min_cost * dist[i];
        if (cost[i] < min_cost)
            min_cost = cost[i];
    }

    cout << total_cost << endl;
    return 0;
}
