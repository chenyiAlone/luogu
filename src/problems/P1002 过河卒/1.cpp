/*

题目描述
棋盘上AA点有一个过河卒，需要走到目标BB点。卒行走的规则：可以向下、或者向右。同时在棋盘上CC点有一个对方的马，该马所在的点和所有跳跃一步可达的点称为对方马的控制点。因此称之为“马拦过河卒”。

棋盘用坐标表示，AA点(0, 0)(0,0)、BB点(n, m)(n,m)(nn, mm为不超过2020的整数)，同样马的位置坐标是需要给出的。

现在要求你计算出卒从AA点能够到达BB点的路径的条数，假设马的位置是固定不动的，并不是卒走一步马走一步。

输入输出格式
输入格式：
一行四个数据，分别表示BB点坐标和马的坐标。

输出格式：
一个数据，表示所有的路径条数。

输入输出样例
输入样例#1： 
6 6 3 3
输出样例#1： 
6
说明
结果可能很大！

思路：
    娘的... 方向 dx 写错了


*/
#include <iostream>
#include <cstring>
using namespace std;

int n, m, x, y, ban[22][22];
unsigned long long f[22][22];

int dx[] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {0, 1, 2, 2, 1, -1, -2, -2, -1};


int main() {
    cin >> n >> m >> x >> y;
    n++; m++;
    for (int i = 0; i < 9; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < m)
            ban[nx][ny] = 1;
    }
    f[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (ban[i - 1][j - 1]) continue;
            f[i][j] = max(f[i][j], f[i - 1][j] + f[i][j - 1]);
        }
    }
    cout << f[n][m];
    return 0;
}