/*

题目背景
无

题目描述
高精度加法,x相当于a+b problem，[b][color=red]不用考虑负数[/color][/b]

输入输出格式
输入格式：
分两行输入a,b<=10^500

输出格式：
输出只有一行，代表A+B的值

输入输出样例
输入样例#1： 
1
1
输出样例#1： 
2


*/
#include <iostream>
using namespace std;
string s1, s2, res;

int main() {
    cin >> s1 >> s2;
    int c = 0;
    for (int i = s1.size() - 1, j = s2.size() - 1; i >= 0 || j >= 0; i--, j--) {
        int a = i >= 0 ? (s1[i] - '0') : 0, b = j >= 0 ? (s2[j] - '0') : 0;
        int sum = (a + b + c);
        res += '0' + sum % 10;
        c = sum / 10;
    }
    if (c != 0) res += '0' + c;
    for (int i = 0, j = res.size() - 1; i < j; i++, j--)
        swap(res[i], res[j]);
    cout << res << endl;
    return 0;
}