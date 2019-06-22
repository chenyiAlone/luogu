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
    int n, m;
    int tmp;
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
    int res = (1ll << 31) - 1;
    for ( ; !que.empty(); que.pop()) {
        mov mo = que.front();
        int x = mo.x, y = mo.y;
        if (x == e_x + 1 && y == e_y + 1) {
            cout << mo.cost;
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int dest_dir = get_dir(dx[i], dy[i]);
            int bit = 1 << next_dir[mo.direct][dest_dir];
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
            trace[x][y] |= bit;
        }
    }
    cout << "-1";
    return 0;
}