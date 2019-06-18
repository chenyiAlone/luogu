#include <iostream>
using namespace std;

int cut(int n, int m) {
    if (m > n) return 0;
    if (m == 1) return n;
    int ret = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            ret = max(ret, cut(i, j) * cut(n - i, m - j));
        }
    }
    return ret;
}

int cut2(int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    if (n == 3) return 2;
    int ret = 0;
    for (int i = 1; i <= n / 2; i++) {
        ret = max(ret, max(i, cut2(i)) * max(n - i, cut2(n - i)));
    }
    return ret;
}


int main() {
    int length, ret = 0;
    cin >> length;
    // for (int i = 2; i < length; i++) {
    //     ret = max(ret, cut(length, i));
    // }
    ret = cut2(length);
    cout << ret;
    return 0;
}