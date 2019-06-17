/*

题目描述
由数字00组成的方阵中，有一任意形状闭合圈，闭合圈由数字11构成，围圈时只走上下左右44个方向。现要求把闭合圈内的所有空间都填写成22.例如：6 \times 66×6的方阵（n=6n=6），涂色前和涂色后的方阵如下：

0 0 0 0 0 0
0 0 1 1 1 1
0 1 1 0 0 1
1 1 0 0 0 1
1 0 0 0 0 1
1 1 1 1 1 1
0 0 0 0 0 0
0 0 1 1 1 1
0 1 1 2 2 1
1 1 2 2 2 1
1 2 2 2 2 1
1 1 1 1 1 1
输入输出格式
输入格式：
每组测试数据第一行一个整数n(1 \le n \le 30)n(1≤n≤30)
接下来nn行，由00和11组成的n \times nn×n的方阵。

方阵内只有一个闭合圈，圈内至少有一个00。

//感谢黄小U饮品指出本题数据和数据格式不一样. 已修改(输入格式)

输出格式：
已经填好数字22的完整方阵。

输入输出样例
输入样例#1： 
6
0 0 0 0 0 0
0 0 1 1 1 1
0 1 1 0 0 1
1 1 0 0 0 1
1 0 0 0 0 1
1 1 1 1 1 1
输出样例#1： 
0 0 0 0 0 0
0 0 1 1 1 1
0 1 1 2 2 1
1 1 2 2 2 1
1 2 2 2 2 1
1 1 1 1 1 1

思路:
    BFS + DFS


*/
#include <iostream>
#include <queue>
using namespace std;
int n, f[30][30], trace[30][30], op[30][30];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
queue< pair<int, int> > que;


void dfs(int x, int y) {
    if (f[x][y] != 0 || op[x][y] == 1) return;
    trace[x][y] = true;
    op[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < n && !trace[nx][ny]) {
            dfs(nx, ny);
        }

    }
    trace[x][y] = false;
}

void bfs() {
    for ( ; que.size() > 0; que.pop()) {
        pair<int, int> p = que.front();
        int x = p.first, y = p.second;
        trace[x][y] = 1;
        if (f[x][y] == 0) {
            op[x][y] = 1;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (0 <= nx && nx < n && 0 <= ny && ny < n && !trace[nx][ny] && f[nx][ny] == 0) {
                    que.push(make_pair(nx, ny));
                }
            }
        }
    }
}


int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) 
            cin >> f[i][j];
    // for (int i = 0; i < n; i++) {
    //     dfs(0, i);  dfs(n - 1, i);  
    //     dfs(i, 0);  dfs(i, n - 1);
    // }
    for (int i = 0; i < n; i++) {
        que.push(make_pair(0, i));
        que.push(make_pair(n - 1, i));
        que.push(make_pair(i, 0));
        que.push(make_pair(i, n - 1));
    }
    bfs();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int c = f[i][j];
            if (c == 0 && op[i][j] == 0) c = 2;
            cout << c << ' ';
            // cout << op[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}