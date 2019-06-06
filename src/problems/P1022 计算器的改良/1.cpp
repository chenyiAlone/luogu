/*

题目背景
NCLNCL是一家专门从事计算器改良与升级的实验室，最近该实验室收到了某公司所委托的一个任务：需要在该公司某型号的计算器上加上解一元一次方程的功能。实验室将这个任务交给了一个刚进入的新手ZL先生。

题目描述
为了很好的完成这个任务，ZLZL先生首先研究了一些一元一次方程的实例：

4+3x=84+3x=8
6a-5+1=2-2a6a−5+1=2−2a
-5+12y=0−5+12y=0
ZLZL先生被主管告之，在计算器上键入的一个一元一次方程中，只包含整数、小写字母及+、-、=这三个数学符号（当然，符号“-”既可作减号，也可作负号）。方程中并没有括号，也没有除号，方程中的字母表示未知数。

你可假设对键入的方程的正确性的判断是由另一个程序员在做，或者说可认为键入的一元一次方程均为合法的，且有唯一实数解。

输入输出格式
输入格式：
一个一元一次方程。

输出格式：
解方程的结果(精确至小数点后三位)。

输入输出样例
输入样例#1： 
6a-5+1=2-2a
输出样例#1： 
a=0.750

思路:

    被这道题玩死了，坑实在是太多了，愣是干了好几个小时
    1. 可能存在空格，开始看输入没有，就默认没有了，结果超时
    2. 1 / 0 => inf 的问题，在 double 中是可以作为被除数的
    3. 0 /-a => -0 c++ 里面 0 除以一个负数结果为 -0

*/
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

long long coef, total;
int lor = 1;
char ukn;

int main() {
    string s = "";
    getline(cin, s);
    int i = 0, len = s.size();
    while (i < len) {
        int temp = -1, sign = 1;
        if (s[i] == '=') {
            lor = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        } else if (s[i] == '-') {
            sign = -1;
            i++;
        }
        if (i < len && '0' <= s[i] && s[i] <= '9') {
            temp = s[i++] - '0';
            while (i < len && '0' <= s[i] && s[i] <= '9') {
                temp = temp * 10 + (s[i] - '0');
                i++;
            }
        } 
        if (i < len && 'a' <= s[i] && s[i] <= 'z') {
            ukn = s[i];
            coef += sign * lor * (temp != -1 ? temp : 1);
            temp = 0;
            i++;
        }
        if (i < len && s[i] != '+' && s[i] != '-' && s[i] != '=')
            i++;
        total += (-lor) * ((temp == -1) ? 0 : temp) * sign;
    }
    double res = 1.0 * total / coef;
    printf("%c=%.3lf", ukn, res == 0 ? abs(res) : res);
    return 0;
}