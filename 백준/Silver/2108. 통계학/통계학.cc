#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int main() {
    int n, num;
    double sum=0;
    int a[8001] = {0,};
    vector<int> v;

    cin >> n;
    
    for(int i=0; i<n; i++) {
        cin >> num;
        v.push_back(num);
        if (num < 0)
            a[4000 - num]++; // 음수는 4001 ~ 8000
        else
            a[num]++; // 양수는 0 ~ 4000
        sum += num;
    }
    sort(v.begin(), v.end());
    

    double size = v.size(), avg;
    if (round(sum / size) == -0)
        avg = 0;
    else
        avg = round(sum / size);
    
    cout << avg << endl;
    
    double index = v.size() / 2;
    cout << v[index] << endl; // 중앙값

    int max = a[0], number=0;
    for (int i = 1; i < 8001; i++) {
        if (max < a[i]) {
            max = a[i];
        }
    }
    
    for (int i = 0; i < 8001; i++) {
        if (max == a[i])
            number++;
    }
    
    vector<int> mv;
    for (int i = 0; i < 8001; i++) {
        if (max == a[i]) {
            if (i <= 4000)
                mv.push_back(i);
            else
                mv.push_back(4000 - i);
        }
    }
    
    sort(mv.begin(), mv.end());
    
    if (number == 1)
        cout << mv[0] << endl;
    else
        cout << mv[1] << endl;
    
    cout << v[v.size()-1] - v[0] << endl; // 범위
    
    return 0;
}
