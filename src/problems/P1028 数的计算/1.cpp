/*

    题目描述
    我们要求找出具有下列性质数的个数(包含输入的自然数nn):

    先输入一个自然数nn(n \le 1000n≤1000),然后对此自然数按照如下方法进行处理:

    不作任何处理;

    在它的左边加上一个自然数,但该自然数不能超过原数的一半;

    加上数后,继续按此规则进行处理,直到不能再加自然数为止.

    输入输出格式
    输入格式：
    11个自然数nn(n \le 1000n≤1000)

    输出格式：
    11个整数，表示具有该性质数的个数。

    输入输出样例
    输入样例#1： 
    6
    输出样例#1： 
    6
    说明
    满足条件的数为

    6，16，26，126，36，136

*/
#include <iostream>
#include <vector>

using namespace std;


int calculate(int n, vector<int> &f) {
    if (f[n] != -1)
        return f[n];
    f[n] = 1;
    for (int i = 1; i <= n/2; i++) {
        f[n] += calculate(i, f);
    }
    return f[n];
}   

// O(n^2)
// f[n] = f[1] + ... + f[n / 2] + 1
void dp1(int n, vector<int> &f) {
    f[0] = 0;
    f[1] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = 1;
        for (int j = 1; j <= i/2; j++) {
            f[i] += f[j];
        }
    }
    for (int i = 0; i <= n; i++) {
        cout << f[i] << ' ';   
    }
    cout << f[n] << endl;
}

// f[n] = f[n - 1] + f[n / 2]
void dp2(int n, vector<int> &f) {
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0)
            f[i] = f[i - 1] + f[i / 2];
        else
            f[i] = f[i - 1];
    }
    // for (int i = 0; i <= n; i++) {
    //     cout << f[i] << ' ';   
    // }
    cout << f[n] << endl;
}

int main() {
    int n;
    cin >> n;
    // 记忆数组
    // vector<int> f(n + 1, -1);
    // cout << calculate(n, f);

    // DP O(n^2)
    // vector<int> f(n + 1, 0);
    // dp1(n, f);
    


    // DP O(n^2)
    vector<int> f(n + 1, 0);
    dp2(n, f);
    
    return 0;
}