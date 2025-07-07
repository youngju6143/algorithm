#include <iostream>
#include <string>
using namespace std;
#define endl '\n'

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    
    string s;
    
    for (int i = 0; i < n; i++) {
        cin >> s;
        int cnt = 0;
        for (int j = 0; j < s.length(); j++) {
            switch(s[j]) {
                case '@':
                    s[j] = 'a';
                    cnt++;
                    break;
                case '[':
                    s[j] = 'c';
                    cnt++;
                    break;
                case '!':
                    s[j] = 'i';
                    cnt++;
                    break;
                case ';':
                    s[j] = 'j';
                    cnt++;
                    break;
                case '^':
                    s[j] = 'n';
                    cnt++;
                    break;
                case '0':
                    s[j] = 'o';
                    cnt++;
                    break;
                case '7':
                    s[j] = 't';
                    cnt++;
                    break;
                case '\\':
                    if (s[j+1] == '\'')
                        s.replace(j, 2, "v");
                    else
                        s.replace(j, 3, "w");
                    cnt++;
                    break;
                default:
                    break;
            }
        }
        bool isTranslated;
        if (s.length() % 2 == 1) {
            if (cnt >= s.length() / 2 + 1)
                isTranslated = false;
            else
                isTranslated = true;
        }
        else {
            if (cnt >= s.length() / 2)
                isTranslated = false;
            else
                isTranslated = true;
        }

        cout << (isTranslated ? s : "I don't understand") << endl;
    }
    
    return 0;
}
