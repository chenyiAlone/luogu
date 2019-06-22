/*
题目描述
机器人移动学会（RMI）现在正尝试用机器人搬运物品。机器人的形状是一个直径$1.6米的球。在试验阶段，机器人被用于在一个储藏室中搬运货物。储藏室是一个N \times MN×M的网格，有些格子为不可移动的障碍。机器人的中心总是在格点上，当然，机器人必须在最短的时间内把物品搬运到指定的地方。机器人接受的指令有：向前移动11步（Creep）；向前移动2步（Walk）；向前移动33步（Run）；向左转（Left）；向右转（Right）。每个指令所需要的时间为11秒。请你计算一下机器人完成任务所需的最少时间。

输入输出格式
输入格式：
第一行为两个正整数N,M(N,M \le 50)N,M(N,M≤50)，下面NN行是储藏室的构造，00表示无障碍，11表示有障碍，数字之间用一个空格隔开。接着一行有44个整数和11个大写字母，分别为起始点和目标点左上角网格的行与列，起始时的面对方向（东EE，南SS，西WW，北NN），数与数，数与字母之间均用一个空格隔开。终点的面向方向是任意的。

输出格式：
一个整数，表示机器人完成任务所需的最少时间。如果无法到达，输出-1−1。



输入输出样例
输入样例#1： 
9 10
0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 0 1 0
0 0 0 1 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 1 0 0 0 0
0 0 0 1 1 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
1 0 0 0 0 0 0 0 1 0
7 2 2 7 S
输出样例#1： 
12


思路:
    



*/

#include <iostream>
#include <queue>
using namespace std;

// -1 不通， 0 转向，直行
// int cost(int nx, int ny, int x, int y, int dx, int dy, int cnt) {
//     if (nx <= 0 || n - 1 <= nx || ny <= 0 || m - 1 >= ny) {
//         if (x + dx == nx && y + dy == ny) {
//             if (cnt < )
//         }
//     }
//     return -1;
// }
/*
0: up
1: down
2: left
3: right
*/
int f[60][60], trace[60][60];
// next dir
int next_dir[4][4] = {  {0, 3, 2, 3},
                        {2, 1, 2, 3},
                        {0, 1, 2, 0},
                        {0, 1, 1, 3}    };
int dir_cost[4][4] = {  {0, 2, 1, 1}, 
                        {2, 0, 1, 1},
                        {1, 1, 0, 2}, 
                        {1, 1, 2, 0}  };

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

typedef struct {
    int x;
    int y;
    int cost;
    int direct;
} mov;
queue< mov > que;

int get_dir(int x, int y) {
    if (x == -1 && y == 0)  return 0;
    if (x == 1 && y == 0)   return 1;
    if (x == 0 && y == -1)  return 2;
    if (x == 0 && y == 1)   return 3;
    return -1;
}


int main() {
    int n, m;
    int tmp;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) {
            // cin >> f[i][j];
            cin >> tmp;
            if (tmp == 1) {
                f[i][j] = 1;
                f[i][j + 1] = 1;
                f[i + 1][j] = 1;
                f[i + 1][j + 1] = 1;
            }
        }
    int b_x, b_y, e_x, e_y;
    cin >> b_x >> b_y >> e_x >> e_y;
    char c;
    cin >> c;

    // for (int i = 1; i <= n + 1; i++) {

    //     for (int j = 1; j <= m + 1; j++) {
    //         // cin >> f[i][j];
    //         cout << f[i][j] << ' ';       
    //     }
    //     cout << endl;
    // }
    // cout << b_x + 1 << ' ' << b_y + 1 << endl;
    int init_dir = 0;
    if (c == 'N') init_dir = 0;
    if (c == 'S') init_dir = 1;
    if (c == 'W') init_dir = 2;
    if (c == 'E') init_dir = 3;
    // cout << "init_dir: " << init_dir << endl;
    que.push(mov {b_x + 1, b_y + 1, 0, init_dir});
    int res = (1ll << 31) - 1;
    for ( ; !que.empty(); que.pop()) {
        mov mo = que.front();
        int x = mo.x, y = mo.y;
        // if (x == 3 && y == 6 && mo.direct == 1)
        //     cout << x << ' ' << y << ' ' << mo.cost << ' ' << mo.direct << endl;
        // f[x][y] = 1;
        // if (trace[x][y] == 1) continue;
        // trace[x][y] = 1;
        if (x == e_x + 1 && y == e_y + 1) {
            cout << mo.cost;
            // cout << "ans: " << x << ' ' << y << ' ' << mo.cost << endl; 
            // res = mo.cost < res ? mo.cost : res;
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int dest_dir = get_dir(dx[i], dy[i]);
            int bit = next_dir[mo.direct][dest_dir];
            // cout << dest_dir << endl;
            // int cost = mo.cost + dir_cost[mo.direct][dest_dir];
            if (dest_dir == mo.direct) {
                for (int j = 1; j <= 3; j++) {
                    int nx = x + j * dx[i], ny = y + j * dy[i];
                    if (1 < nx && nx <= n && 1 < ny && ny <= m && trace[nx][ny] == 0) {
                        if (f[nx][ny] == 1) break;
                        // cout << nx << ' ' << ny << endl;
                        // trace[nx][ny] = 1;
                        que.push(mov {nx, ny, mo.cost + 1, dest_dir});
                    }
                }
            } else {
                if ((trace[x][y] & (1 << bit)) == 0) {
                    que.push(mov {x, y, mo.cost + 1, next_dir[mo.direct][dest_dir]});
                }
            }
            trace[x][y] |= (1 << bit);
        }
        // trace[x][y] = 1;
    }
    cout << "-1";
    // cout << res;
    // cout << 3 % 3;

    return 0;
}
            // int nx = x + dx[i], ny = y + dy[i];
            // if (1 < nx && nx <= n && 1 < ny && ny <= m && f[nx][ny] != 1) {
            //     int cost = mo.cost, dest_dir = get_dir(dx[i], dy[i]);
            //     if (dest_dir == mo.direst) {
            //         for (int i = 1; i <= 3; i++) {
            //             que.push(mov {nx, ny, cost, dir});
            //         }
            //     }


                // cost += dir_cost[mo.direct][dest_dir]; // 转向花费
                // if (dest_dir == mo.direct) {
                //     if (resi < 3) {
                //         resi += 1;
                //     } else {
                //         cost += 1;
                //         resi = 1;
                //     }
                // } else {
                //     cost += 1;
                //     resi = 1;
                // }
                // que.push(mov {nx, ny, cost, dest_dir});
            // }