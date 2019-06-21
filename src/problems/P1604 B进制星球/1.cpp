#include <iostream>
#define itoc(i) (0 <= i && i <= 9 ? ('0' + i) : ('A' + i - 10))
#define ctoi(c) ('0' <= c && c <= '9' ? (c - '0') : (10 + c - 'A'))
using namespace std;

int base;

void add(string &a, string &b, string &c) {
    int la = a.size(), lb = b.size(), cy = 0;
    for (int i = la - 1, j = lb - 1; i >= 0 || j >= 0; i--, j--) {
        int n1 = i < 0 ? 0 : ctoi(a[i]), n2 = j < 0 ? 0 : ctoi(b[j]);
        int sum = n1 + n2 + cy;
        c += itoc(sum % base);
        cy = sum / base;
    }
    if (cy != 0) c += itoc(cy);
    for (int i = 0, j = (int)c.size() - 1; i < j; i++, j--) swap(c[i], c[j]);
}

int main() {
    string a, b, c;
    cin >> base >> a >> b;
    add(a, b, c);
    cout << c << endl; 
    return 0;
}