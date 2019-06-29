/*

使用一位数组对 01 背包进行压缩的过程本身就是为了省略 从 f[i - 1][j] 到 f[i][j] 的状态转移

*/
#include <iostream>
#include <vector>
using namespace std;

int t, m;
vector<int> f(1001);
vector<int> values(1001);
vector<int> cost(101);

int main() {
    cin >> t >> m;
    for (int i = 1; i <= m; i++)
        cin >> cost[i] >> values[i];
    for (int i = 1; i <= m; i++) {
        for (int j = t; j >= cost[i]; j--) {
            f[j] = max(f[j], f[j - cost[i]] + values[i]);
        }
    }
    cout << f[t];
    return 0;
}