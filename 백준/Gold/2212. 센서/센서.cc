#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define endl '\n'

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    vector<int> sensors, distances;
    int n, k, sensor;

    cin >> n;
    cin >> k;

    for (int i = 0; i < n; i++) {
        cin >> sensor;
        sensors.push_back(sensor);
    }
    
    sort(sensors.begin(), sensors.end());
    for (int i = 0; i < n-1; i++) {
        distances.push_back(sensors[i+1] - sensors[i]);
    }

    sort(distances.begin(), distances.end());
    
    int cnt=0, sum=0;
    while(1) {
        if (cnt == k-1 || distances.size() == 0) break;
        distances.pop_back();
        cnt++;
    }
    
    for (int i = 0; i < distances.size(); i++)
        sum += distances[i];
    
    cout << sum << endl;
    
    return 0;
}
