#include <iostream>
using namespace std;

int main() {
    int k;
    string s;
    cin >> k >> s;
    int len = s.size();
    for (int i = 0; i < len; i++) {
        s[i] = (s[i] - 'a' + k) % 26 + 'a';
    }
    cout << s;
    return 0;
}
