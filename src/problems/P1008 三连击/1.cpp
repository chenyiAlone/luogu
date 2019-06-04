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

int apartNum(int f[], int num) {
    if (!(num / 100 % 10) || !(num / 10 % 10) || !(num % 10))
        return 0;
    if (f[num / 100 % 10]) 
        return 0;
    else
        f[num / 100 % 10] = 1;
    
    if (f[num / 10 % 10])
        return 0;
    else
        f[num / 10 % 10] = 1;
    if (f[num % 10])
        return 0;
    else
        f[num % 10] = 1;
    return 1;
}

int main() {
    // 1000 / 6
    for (int i = 100; i < 328; i++) {
        int f[10] = {0}; 
        if (apartNum(f, i))
            if (apartNum(f, i * 2) && apartNum(f, i * 3) && i * 3 < 1000)
                cout << i << ' ' << i * 2 << ' ' << i * 3 << endl;            
    }
    // int f2[10] = {0}; 
    // cout << apartNum(f2, 111);
    return 0;
}