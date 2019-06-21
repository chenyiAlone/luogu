#include <iostream>
#include <cstring>
using namespace std;
bool flag;
string s1, s2;

bool cmp(string &a, string &b) {
    int la = a.size(), lb = b.size();
    if (la != lb) return la < lb;
    for (int i = 0; i <= la - 1; i--) {
        if (a[i] != b[i]) return a[i] < b[i];
    }
    return false;
}

int main() {    
    cin >> s1 >> s2;
    if (cmp(s1, s2)) {  // a - b
        flag = true;
        swap(s1, s2);
    } 
    for (int i = 0, j = (int)s2.size() - s1.size(); i < s1.size(); i++, j++) {
        int a = s1[i] - '0', b = (j < 0 ? 0 : (s2[j] - '0'));
        if (a < b) {
            a += 10;
            int t = i - 1;
            while (s1[t] == '0') {
                s1[t] = '9';
                t--;
            }
            s1[t] -= 1;
        }
        int ans = a - b;
        s1[i] = '0' + ans;
    }
    int start = 0;
    while (s1[start] == '0' && start + 1 < s1.size()) start++;
    s1 = s1.substr(start);
    if (flag) s1 = '-' + s1;
    cout << s1 << endl;
    return 0;
}