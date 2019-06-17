#include <iostream>
#include <vector>
using namespace std;
int n, root[32][32], weight[32][32];
vector<int> values;

int dfs(int l, int r) {
    if (weight[l][r] != 0)
        return weight[l][r];
    weight[l][r] = 1;
    if (l > r) {
        if (l == r) {
            weight[l][r] = values[l];
            root[l][r] = l;
        }
    } else {
        for (int i = l; i <= r; i++) {
            int lv = dfs(l, i - 1);
            int rv = dfs(i + 1, r);
            if (lv * rv + values[i] > weight[l][r]) {
                weight[l][r] = lv * rv + values[i];
                root[l][r] = i;
            }
        }
    }
    return weight[l][r];
}

void pre_order(int l, int r) {
    if (l > r) return;
    cout << root[l][r] << ' ';
    if (l == r) return;
    pre_order(l, root[l][r] - 1);
    pre_order(root[l][r] + 1, r);
}

int main() {
    cin >> n;
    values = vector<int>(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> values[i];
    cout << dfs(1, n) << endl;
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << root[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    pre_order(1, n);
    return 0;

}