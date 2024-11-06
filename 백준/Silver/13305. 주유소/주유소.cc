#include <iostream>
using namespace std;

int main(){
    
    int n;
    int dist[100000], cost[100000];
    long long total=0, now;
    
    cin >> n;
    
    for(int i = 1; i < n; i++){
        cin >> dist[i];
    }
    
    for(int i = 0; i < n; i++){
        cin >> cost[i];
    }
    now = cost[0];
    total = now * dist[1];
    
    for(int i = 1; i < n; i++){
        if(now < cost[i]){
            total += now * dist[i+1];
        }
        else{
            now = cost[i];
            total += now * dist[i+1];
        }
    }
    cout << total << endl;
    return 0;
}
