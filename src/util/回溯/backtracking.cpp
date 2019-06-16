#include <iostream>
using namespace std;
void dfs1(int, int);
void dfs2(int, int);

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int f[6][6], trace[6][6], m, n, t, bx, by, ex, ey, res = 0;

// 进入前标记，退出后取消
void exec_dfs1(int x, int y) {
    trace[x][y] = true;
    dfs1(x, y);
    trace[x][y] = false;
}

void dfs1(int x, int y) {
    if (x == ex && y == ey) {
        res++;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (0 < nx && nx <= n && 0 < ny && ny <= m && f[nx][ny] == 0 && trace[nx][ny] == 0) {
            trace[nx][ny] = true;
            dfs1(nx, ny);
            trace[nx][ny] = false;
        }
    }
}

// 进入后标记，退出前取消
void exec_dfs2(int x, int y) {
    dfs2(x, y);
}

void dfs2(int x, int y) {
    trace[x][y] = 1;
    if (x == ex && y == ey) {
        res++;
    } else {
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (0 < nx && nx <= n && 0 < ny && ny <= m && f[nx][ny] == 0 && trace[nx][ny] == 0)
                dfs2(nx, ny);
        }
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
    exec_dfs1(bx, by);
    // exec_dfs2(bx, by);
    cout << res;
    return 0;
}