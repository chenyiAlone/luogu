/*

题目描述
有一个n*m的棋盘(1<n,m<=400)，在某个点上有一个马,要求你计算出马到达棋盘上任意一个点最少要走几步

输入输出格式
输入格式：
一行四个数据，棋盘的大小和马的坐标

输出格式：
一个n*m的矩阵，代表马到达某个点最少要走几步（左对齐，宽5格，不能到达则输出-1）

输入输出样例
输入样例#1： 
3 3 1 1
输出样例#1： 
0    3    2    
3    -1   1    
2    1    4    


思路:
    注意输出格式


*/

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
int n, m, s_x, s_y,f[401][401];
queue< pair<int, int> > que;
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int main() {
    memset(f, -1, sizeof(f));
    cin >> n >> m >> s_x >> s_y;
    f[s_x][s_y] = 0;
    que.push(make_pair(s_x, s_y));
    for ( ; !que.empty(); que.pop()) {
        pair<int, int> p = que.front();
        int x = p.first, y = p.second;
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (1 <= nx && nx <= n && 1 <= ny && ny <= m && f[nx][ny] == -1) {
                f[nx][ny] = f[x][y] + 1;
                que.push(make_pair(nx, ny));
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // cout << f[i][j] << (j == m ? "\n" : " ");
            printf("%-5d", f[i][j]);
        }
        cout << endl;
    }
    return 0;
}