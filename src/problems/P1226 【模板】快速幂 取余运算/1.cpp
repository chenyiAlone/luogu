/*

题目描述
输入b，p，k的值，求b^p mod k的值。其中b，p，k*k为长整型数。

输入输出格式
输入格式：
三个整数b,p,k.

输出格式：
输出“b^p mod k=s”

s为运算结果

输入输出样例
输入样例#1： 
2 10 9
输出样例#1： 
2^10 mod 9=7

思路：
    a ^ B = a ^ b1 + a ^ b2 + ... + a ^ bn 
    B = 2 ^ c1 + 2 ^ c2 + ... + 2 ^ cn; (这里的 c 的值为 1 或者 0)
    进而，可以将 B 用二进制表示，而对应的 ci 也就是该位上的值
    B = 1 ^ d1 + 10 ^ d2 + 100 ^ d3 + .. + 1000...0 ^ dn;


*/

#include <iostream>
using namespace std;
long long b, p, k;
int main() {
    cin >> b >> p >> k;
    long long m = b, n = p, res = 1;
    while (n > 0) {
        if ((n & 1) == 1)
             res = res * m % k;
        m = m * m % k;
        n >>= 1;
    }
    cout << b << "^" << p << " mod " << k << "=" << res;
    return 0;
}