/*

    题目描述
    给你n根火柴棍，你可以拼出多少个形如“A+B=CA+B=C”的等式？等式中的AA、BB、CC是用火柴棍拼出的整数（若该数非零，则最高位不能是00）。用火柴棍拼数字0-90−9的拼法如图所示：



    注意：

    加号与等号各自需要两根火柴棍

    如果A≠BA≠B，则A+B=CA+B=C与B+A=CB+A=C视为不同的等式(A,B,C>=0A,B,C>=0)

    nn根火柴棍必须全部用上

    输入输出格式
    输入格式：
    一个整数n(n<=24)n(n<=24)。

    输出格式：
    一个整数，能拼成的不同等式的数目。

    输入输出样例
    输入样例#1： 
    14
    输出样例#1： 
    2
    输入样例#2： 
    18
    输出样例#2： 
    9

*/

#include <iostream>
using namespace std;
//              0  1  2  3  4  5  6  7  8  9
int nums[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};


// do{} while(); 来避免 n == 0 的情况
int total(int n) {
    int ret = 0;
    do {
        ret += nums[n % 10];
        n /= 10;
    } while (n > 0);
    return ret;
}

int main() {
    int n;
    cin >> n;
    int res = 0;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            if (total(i) + total(j) + total(i + j) + 4 == n)
                res++;
        }
    }
    cout << res << endl;
    return 0;
}