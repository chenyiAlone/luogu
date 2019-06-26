/*

题目描述
有一个箱子容量为VV（正整数，0 \le V \le 200000≤V≤20000），同时有nn个物品（0<n \le 300<n≤30，每个物品有一个体积（正整数）。

要求nn个物品中，任取若干个装入箱内，使箱子的剩余空间为最小。

输入输出格式
输入格式：
11个整数，表示箱子容量

11个整数，表示有nn个物品

接下来nn行，分别表示这nn个物品的各自体积

输出格式：
11个整数，表示箱子剩余空间。

输入输出样例
输入样例#1： 
24
6
8
3
12
7
9
7
输出样例#1： 
0



*/
#include <iostream>
using namespace std;
int n, m;
int f[31][20003] = {}, bulk[32];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> bulk[i];
    for (int i = 1; i <= m; i++) {
        // for (int j = n; j >= bulk[i]; j--) {
        for (int j = 0; j <= n; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= bulk[i])
                f[i][j] = max(f[i - 1][j], f[i - 1][j - bulk[i]] + bulk[i]);
        }
    }
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++)
            cout << f[i][j] << ' ';
        cout << endl;
    }
    cout << n - f[m][n];
    return 0;
}