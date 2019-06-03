/*

    题目描述
    因为151既是一个质数又是一个回文数(从左到右和从右到左是看一样的)，所以 151 是回文质数。

    写一个程序来找出范围[a,b](5 <= a < b <= 100,000,000)( 一亿)间的所有回文质数;

    输入输出格式
    输入格式：
    第 1 行: 二个整数 a 和 b .

    输出格式：
    输出一个回文质数的列表，一行一个。

    输入输出样例
    输入样例#1： 
    5 500
    输出样例#1： 
    5
    7
    11
    101
    131
    151
    181
    191
    313
    353
    373
    383
    说明
    Hint 1: Generate the palindromes and see if they are prime.

    提示 1: 找出所有的回文数再判断它们是不是质数（素数）.

    Hint 2: Generate palindromes by combining digits properly. You might need more than one of the loops like below.

    提示 2: 要产生正确的回文数，你可能需要几个像下面这样的循环。

    题目翻译来自NOCOW。

    USACO Training Section 1.5

    产生长度为5的回文数:

    for (d1 = 1; d1 <= 9; d1+=2) {    // 只有奇数才会是素数
        for (d2 = 0; d2 <= 9; d2++) {
            for (d3 = 0; d3 <= 9; d3++) {
            palindrome = 10000*d1 + 1000*d2 +100*d3 + 10*d2 + d1;//(处理回文数...)
            }
        }
    }

*/

#include <iostream>
#include <math.h>

using namespace std;

int lboard, rboard;

bool isPrime(int n) {
    for (int i = 2; i <= (int)sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

void build(int l, int r, int sum, int cnt, int len) {
    if (l < r || cnt <= 0) {
        if (sum >= lboard && cnt == 0 && isPrime(sum))
            cout << sum << endl; 
        return;
    }
    for (int j = (len == 1 ? 5 : (r == 0 ? 1 : 0)); j <= 9; j += (r == 0 ? 2 : 1)) {
        int temp = 0;
        if (l == r) {
            temp = (int)pow(10, r) * j;
        } else {
            temp = (int)pow(10, l) * j + (int)pow(10, r) * j;
        }
        if (sum + temp > rboard)
            break;
        build(l -1, r + 1, sum + temp, cnt - (l == r ? 1 : 2), len);
    }
}

int len(int n) {
    int ret = 0;
    while (n > 0) {
        ret++;
        n /= 10;
    }
    return ret;
}

int main() {
    
    cin >> lboard >> rboard;
    int llen = len(lboard), rlen = len(rboard);

    for (int i = llen - 1; i < rlen; i++) {
        build(i, 0, 0, i + 1, i + 1);
    }
    return 0;
}