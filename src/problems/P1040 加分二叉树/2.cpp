

/*

思路：
    f[i][j] 的值只依赖于当前的位置前面和下面的值，所有需要从下向上，从左向右进行递推


f[i-2][j-2]   f[i-1][j-1]   f[i][j]
         X        X       
            X         X
               X         X
                  X         f[i+1][j]
                     X
                         X
                            f[i+2][j]


*/

#include <iostream>
using namespace std;
int n, f[32][32], root[32][32];

void pre_order(int l, int r) {
    if (l >= r) {
        if (l == r) cout << l << ' ';
        return;
    }
    cout << root[l][r] << ' ';
    pre_order(l, root[l][r] - 1);
    pre_order(root[l][r] + 1, r);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> f[i][i];
        f[i][i - 1] = 1;
    }
    for (int i = n; i >= 1; i--) {
        for (int j = i + 1; j <= n; j++) {
            for (int k = i; k <= j; k++) {
                if (f[i][j] < f[i][k - 1] * f[k + 1][j] + f[k][k]) {
                    f[i][j] = f[i][k - 1] * f[k + 1][j] + f[k][k];
                    root[i][j] = k;
                }
            }
        }
    }
    cout << f[1][n] << endl;
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << root[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    pre_order(1, n);
    return 0;
}