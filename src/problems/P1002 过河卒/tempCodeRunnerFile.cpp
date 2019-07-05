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