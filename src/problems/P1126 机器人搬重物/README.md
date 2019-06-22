
# 题目描述

机器人移动学会（RMI）现在正尝试用机器人搬运物品。机器人的形状是一个直径$1.6米的球。在试验阶段，机器人被用于在一个储藏室中搬运货物。储藏室是一个`N × M` 的网格，有些格子为不可移动的障碍。机器人的中心总是在格点上，当然，机器人必须在最短的时间内把物品搬运到指定的地方。机器人接受的指令有：向前移动11步（Creep）；向前移动2步（Walk）；向前移动33步（Run）；向左转（Left）；向右转（Right）。每个指令所需要的时间为11秒。请你计算一下机器人完成任务所需的最少时间。

## 输入输出格式
输入格式：
第一行为两个正整数 **`N,M(N,M <= 50)`**，下面NN行是储藏室的构造，`0` 表示无障碍，`1` 表示有障碍，数字之间用一个空格隔开。接着一行有 `4` 个整数和 `1` 个大写字母，分别为起始点和目标点左上角网格的行与列，起始时的面对方向（东E，南S，西W，北N），数与数，数与字母之间均用一个空格隔开。终点的面向方向是任意的。


## 输出格式：
一个整数，表示机器人完成任务所需的最少时间。如果无法到达，输出 `-1`。



## 输入输出样例

### 输入样例#1： 

```
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
```

### 输出样例#1： 

```
12
```



# 思路

1. 广搜 + 每一位的四个方向的判断
2. **注意单元操作**，这里的 **一次转向** 和 **一个方向走 `1 ~ 3` 步** 都花费 `1`


## 辅助数组
|             数组名             |                                       用途                                             |
|:-----------------------------:|:--------------------------------------------------------------------------------------:|
| `trace[i][j]`                   | 用来记录遍历过的位置，其中每个位置的四个方向用 `trace[i][j]` 的二进制表示                   |
| `dir_cost[cur_dir][dest_dir]` | 用来记录从当前方向转向下一个方向的花费                                                     |
| `next_dir[cur_dir][dest_dir]` | 从当前的方向转向的下一个方向，这里每次只转一次，维持广搜的特性（最短路径，对应这里的最少的操作）|
 

<!-- more -->


## 结构体

|   mov   | param |
|:-------:|:-----:|
|  x, y   |  坐标 |
| direct  |  方向 |
|   cost  |  步数 |

## 定义方向

|   | direction |
|:-:|:---------:|
| 0 |    up     |
| 1 |   down    |
| 2 |   left    |
| 3 |  right    |


## 图的转化

1. 走的位置并不是看到的位置，而是给出矩阵的交点处
    - 初始化为 `f[n + 2][m + 2]`，多给出一行一列
    - 如果 `stin[i][j] == 1`，将 `f[i][j]  f[i][j + 1]  f[i + 1][j]  f[i + 1][j + 1]` 都置为 `1`
2. 注意最外圈界是不能走的，所以 `x, y` 的范围为 `1 < x && x <= n` 和 `1 < y && y <= m`

    转化完成的数组，只需要搜索里面的不为 `1` 的位置即可

## 搜索

1. 将开始位置 `start_x + 1, start_y + 1` 以及 **对应的方向** 创建为一个结构体压入队列中
2. 遍历四个方向
    - 方向相同
        - 尝试走 `1 ~ 3` 步，如果中途碰到为 `f[nx][ny] == 1` 的位置，就跳出步进尝试的循环
    - 方向不同
        - 判断 **当前方向** 向 **目标方向** 转化的时候的 **下一个方向** 是否已经遍历过
            - `int bit = 1 << next_dir[cur_dir][dest_dir];  if ((trace[x][y] & bit) == 0)`
            - 没有遍历过就将 `x, y` 的这个方向压入队列中
    - `trace[x][y] |= bit;` 将这位置的该方向标记为已遍历
3. 第一次到达目标位置 `end_x, end_y` 的时候，就打印结果结束程序

# Coding

```cpp
#include <iostream>
#include <queue>
using namespace std;


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
    int n, m, tmp;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) {
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

    int init_dir = 0;
    if (c == 'N') init_dir = 0;
    if (c == 'S') init_dir = 1;
    if (c == 'W') init_dir = 2;
    if (c == 'E') init_dir = 3;

    que.push(mov {b_x + 1, b_y + 1, 0, init_dir});
    for ( ; !que.empty(); que.pop()) {
        mov mo = que.front();
        int x = mo.x, y = mo.y;
        if (x == e_x + 1 && y == e_y + 1) {
            cout << mo.cost;
            return 0;
        }
        for (int i = 0; i < 4; i++) {   // 枚举四个方向
            int dest_dir = get_dir(dx[i], dy[i]);
            int bit = 1 << next_dir[mo.direct][dest_dir];    // 下一个方向
            if (dest_dir == mo.direct) {
                for (int j = 1; j <= 3; j++) {
                    int nx = x + j * dx[i], ny = y + j * dy[i];
                    if (1 < nx && nx <= n && 1 < ny && ny <= m && (trace[nx][ny] & bit) == 0) {
                        if (f[nx][ny] == 1) break;
                        que.push(mov {nx, ny, mo.cost + 1, dest_dir});
                    }
                }
            } else {
                if ((trace[x][y] & bit) == 0) {
                    que.push(mov {x, y, mo.cost + 1, next_dir[mo.direct][dest_dir]});
                }
            }
            trace[x][y] |= bit;  // 标记该方向
        }
    }
    cout << "-1";
    return 0;
}
```
