#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'

void star(int i, int j, int n) {
    if((i / n) % 3 == 1 && (j / n) % 3 == 1)
        cout << ' ';
    else {
        if(n / 3 == 0)
            cout <<'*';
        else
            star(i,j,n/3);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
       
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            star(i,j,n);
        
        cout << endl;
    }
}
