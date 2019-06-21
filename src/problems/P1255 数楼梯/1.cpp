#include <iostream>
#include <cstring>
using namespace std;

int n;
string f[5002];

void add(string &a, string &b, string &c) {
    int la = a.size(), lb = b.size(), cy = 0;
    for (int i = la - 1, j = lb - 1; i >= 0 || j >= 0; i--, j--) {
        int n1 = i < 0 ? 0 : (a[i] - '0'), n2 = j < 0 ? 0 : (b[j] - '0');
        int sum = n1 + n2 + cy;
        c += '0' + sum % 10;
        cy = sum / 10;
    }
    if (cy != 0) c += '0' + cy;
    for (int i = 0, j = (int)c.size() -1; i < j; i++, j--) swap(c[i], c[j]);
}

int main() {
    cin >> n;
    f[0] = "1";   f[1] = "1";
    for (int i = 1; i <= n; i++) {
        add(f[i], f[i - 1], f[i + 1]);
    }
    cout << (n == 0 ? "0" : f[n]) << endl;
    return 0;
}