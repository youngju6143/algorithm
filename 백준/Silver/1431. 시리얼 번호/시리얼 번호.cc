#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <utility>
#include <tuple>


using namespace std;

struct Item {
    string s;
    unsigned long len;
    int sum;
};

bool compare(Item a, Item b) {
    if (a.len == b.len) {
        if (a.sum == b.sum)
            return a.s < b.s;
        return a.sum < b.sum;
    }
    return a.len < b.len;
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    vector<Item> v;

    int n, sum=0;
    string s;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < s.length(); j++) {
            if (isdigit(s[j]))
                sum += s[j] - '0';
        }
        v.push_back({s, s.length(), sum});
        sum = 0;
    }

    sort(v.begin(), v.end(), compare);
    
    for (int i = 0; i < v.size(); i++) {
        cout << v[i].s << endl;
    }
    return 0;
}
