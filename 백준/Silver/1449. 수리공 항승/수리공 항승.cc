#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define endl '\n'

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    vector<int> positions;
    int n, l, position;

    cin >> n >> l;

    for (int i = 0; i < n; i++) {
        cin >> position;
        positions.push_back(position);
    }
    
    sort(positions.begin(), positions.end());

    int cnt=0;
    double end=0;

    for (int i = 0; i < n; i++) {
        if (positions[i] + 0.5 <= end) continue;
        end = positions[i] - 0.5 + l;
        cnt++;
    }
    
    cout << cnt << endl;
    
    return 0;
}
