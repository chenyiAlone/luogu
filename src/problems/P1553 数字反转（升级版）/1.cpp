#include <iostream>
#include <stack>

using namespace std;

int main() {
    string s; 
    cin >> s;
    s += ' ';
    stack<char> stk;
    int len = s.size();
    string res = "";
    for (int i = 0; i < len; i++) {
        if ('0' <= s[i] && s[i] <= '9') {
            stk.push(s[i]);
        } else {
            while (stk.size() > 1 && stk.top() == '0') {
                stk.pop();
            }
            for ( ; !stk.empty(); stk.pop()) {
                res += stk.top();
            }
            res += s[i];
            if (s[i] == '.') {
                while (i + 3 < len && s[i + 1] == '0')
                i++;
            }
        }
    }
    cout << res;
    return 0;
}