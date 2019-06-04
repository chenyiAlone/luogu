/*

题目背景
原来的题目太简单，现改进让小鱼周末也休息，请已经做过重做该题。

题目描述
有一只小鱼，它上午游泳150公里，下午游泳100公里，晚上和周末都休息（实行双休日)，假设从周x(1<=x<=7)开始算起，请问这样过了n天以后，小鱼一共累计游泳了多少公里呢？

输入输出格式
输入格式：
输入两个整数x,n(表示从周x算起，经过n天，n在long int范围内）。

输出格式：
输出一个整数，表示小鱼累计游泳了多少公里。

输入输出样例
输入样例#1： 
3 10
输出样例#1： 
2000

*/
#include <iostream>
using namespace std;

int main() {
    int s, d;
    cin >> s >> d;
    int rest = d / 7 * 2;
    int t = d % 7;
    int temp;
    if ((temp = s + t - 6) > 0 && t > 0) {
        if (s == 7 || temp == 1) {
            rest += 1;
        } else {
            rest += 2;
        }
    }
    cout << 250 * (d - rest);
    return 0;
}