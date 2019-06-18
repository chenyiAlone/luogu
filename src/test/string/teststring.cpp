#include <iostream>
#include <string.h>
using namespace std;
int find(string &t, string &p) {
    int lt = t.size(), lp = p.size();
    if (lp > lt) return -1;
    for (int i = 0; i < lt - lp; i++) {
        int cnt = 0;
        for (int j = 0; j < lp; j++) {
            if (t[i + j] != p[j]) break;
            cnt++;
        }
        if (cnt == lp) return i;
    }
    return -1;
}

int main() {
    string a("111");
    string b("211");
    string c("11");
    cout << "a.compare(b): " << a.compare(b) << endl;
    cout << "a == b: " << (a == b) << endl;
    cout << "a == c: " << (a == c) << endl;
    cout << "a.compare(c): " << a.compare(c) << endl;

    cout << b.find(c) << endl;
    string s1 = "1abcd";
    string s2 = "abc";
    cout << s1.find(s2) << endl;
    cout << s1.substr(0, 1) << "y" << s1.substr(1 + 2) << endl;
    cout << find(s1, s2);
    return 0;
}