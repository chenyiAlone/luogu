#include <iostream>
using namespace std;
int main() {
    string s;
    string m = "0123456789X";
    cin >> s;
    int len = s.size();
    for (int i = 0, code = 0, cnt = 1; i < len; i++) {
        if (s[i] == '-')
            continue;
        if (i == len - 1) {
            if (s[i] == m[code % 11]) {
                cout << "Right";
            }  else {
                s[i] = m[code % 11];
                cout << s;
            }
            return 0;
        } else {
            code += (s[i] - '0') * cnt++;
        }
    }
    return 0;
}