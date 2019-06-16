/*

题目背景
迷宫 【问题描述】

给定一个N*M方格的迷宫，迷宫里有T处障碍，障碍处不可通过。给定起点坐标和

终点坐标，问: 每个方格最多经过1次，有多少种从起点坐标到终点坐标的方案。在迷宫

中移动有上下左右四种方式，每次只能移动一个方格。数据保证起点上没有障碍。

输入样例 输出样例

【数据规模】

1≤N,M≤5

题目描述
输入输出格式
输入格式：
【输入】

第一行N、M和T，N为行，M为列，T为障碍总数。第二行起点坐标SX,SY，终点

坐标FX,FY。接下来T行，每行为障碍点的坐标。

输出格式：
【输出】

给定起点坐标和终点坐标，问每个方格最多经过1次，从起点坐标到终点坐标的方

案总数。

输入输出样例
输入样例#1： 
2 2 1
1 1 2 2
1 2
输出样例#1： 
1

思路:
    1. 看清楚题目要求，不要因为
    2. 关于回溯的写法


*/

#include <iostream>
using namespace std;
int f[6][6], trace[6][6], m, n, t, bx, by, ex, ey, res = 0;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y) {
    if (x == ex && y == ey) {
        res++;
        return;
    }
    trace[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (0 < nx && nx <= n && 0 < ny && ny <= m && f[nx][ny] == 0 && trace[nx][ny] == 0)
            dfs(nx, ny);
    }
    trace[x][y] = 0;
}


int main() {
    cin >> n >> m >> t;
    cin >> bx >> by >> ex >> ey;
    for (int i = 0, x, y; i < t; i++) {
        cin >> x >> y;
        f[x][y] = 1;
    }
    dfs(bx, by);
    cout << res;
    return 0;
}