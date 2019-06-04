#include <iostream>

using namespace std;

int f[5001][1001];
int height[5001], cost[5001];

int main() {
    int n, s, a, b;
    cin >> n >> s >> a >> b;
    
    for (int i = 1; i <= n; i++)
        cin >> height[i] >> cost[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= s; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= cost[i] && b + a >= height[i])
                f[i][j] = max(f[i][j], f[i - 1][j - cost[i]] + 1);
        }
    }
    cout << f[n][s];
    return 0;
}