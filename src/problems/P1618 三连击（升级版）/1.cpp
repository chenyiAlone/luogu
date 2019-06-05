/*

题目背景
本题为提交答案题，您可以写程序或手算在本机上算出答案后，直接提交答案文本，也可提交答案生成程序。

题目描述
将1,2, \cdots ,91,2,⋯,9共99个数分成33组，分别组成33个三位数，且使这33个三位数构成1:2:31:2:3的比例，试求出所有满足条件的33个三位数。

输入输出格式
输入格式：
木有输入

输出格式：
若干行，每行33个数字。按照每行第11个数字升序排列。

输入输出样例
输入样例#1： 
无
输出样例#1： 
192 384 576
* * *
...

* * *
（输出被和谐了）

*/
#include <iostream>
using namespace std;

bool unrepate(int x, bool f[]) {
    f[0] = true;
    int a = x / 100 % 10, b = x / 10 % 10, c = x % 10;
    if (a == b || a == c || b == c || f[a] || f[b] || f[c]) {
        return false;
    }
    f[a] = true;
    f[b] = true;
    f[c] = true;
    return true;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int n = (int) 1000.0 / c * a;
    bool has = false;
    for (double i = 100; i <= n; i++) {
        double na = i, nb = i * b / a, nc = i * c / a;
        bool f[10] = {false};
        if (na == (int)na && nb == (int)nb && nc == (int)nc && unrepate(na, f) && unrepate(nb, f) && unrepate(nc, f)) {
            has = true;
            cout << (int)na << ' ' << (int)nb << ' ' << (int)nc << endl;
        }
    }
    if (!has)
        cout << "No!!!" << endl;
    return 0;
}