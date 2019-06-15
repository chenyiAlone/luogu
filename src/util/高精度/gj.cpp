#include <iostream>
#define N 100
using namespace std;

int f[N], ans[N], k[N], lk = 1, al = 1;;

void h_mul(int x) {
    for (int i = 1; i <= lk; i++) k[i] *= x;
    lk += 4; // 长度变为原来长度加上 a 的范围的十进制表示长度
    for (int i = 1; i <= lk; i++) {
        k[i + 1] = k[i] / 10;
        k[i] %= 10;
    }
    while (k[lk] == 0) lk--;
}

void h_div(int x) {
    bool flag = 1;
    int w = 0;
    for (int i = lk; i >= 0; i--) {
        w = w * 10 + k[i];
        ans[i] = w / x;
        w %= x;
        if (flag && ans[i] != 0) {  // 用来更新 ans 的长度，也就是最高位的下标
            al = i;
            flag = 0;
        }
    }
}


int main() {
    k[1] = 1;
    h_mul(2);
    h_mul(22);
    h_div(4);
    for (int i = lk; i != 0; i--) {
        cout << k[i];
    }
    cout << endl;
    for (int i = al; i != 0; i--) {
        cout << ans[i];
    }

    return 0;
}