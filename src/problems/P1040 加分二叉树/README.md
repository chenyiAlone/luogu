## 加分二叉树

### DFS

1. 递归结束条件:
    - `l > r,  return 1;` 对应左右节点有一个为 `null` 的情况，此时 `weight[l][r] = 1`
    - `l == r, return values[l];` 对应 `l ~ l` 区间中只有一个元素，`weight[l][r] = values[l], root[l][r] = l`
    - `l ~ r`，以 `k` 作为 `root` 寻找 `l ~ r` 区间内的最大值 `weight[l][r] = max{weight[l][k - 1] * weight[k + 1][r] + weight[k][k]} (l <= k && k <= r), root[l][r] = k (only is max weight)`

2. 保存树的先序遍历的顺序
    - 记录 `l ~ r` 中间对应的 `root` 根节点的下标，在
    - 打印的时候只需要对应的 `root[l][r]` 得到 `l ~ r` 中间的 `k` 值，递归求 `l ~ k - 1` 和 `k + 1 ~ r` 即可

#### DFS coding

```cpp

    void pre_order(int l, int r) {
        if (l > r) return;
        cout << root[l][r] << ' ';
        if (l == r) return;
        pre_order(l, root[l][r] - 1);
        pre_order(root[l][r] + 1, r);
    }

```


### DP

1. `f[i][j]` 的值依赖于这个位置向左和向下所有的相对的元素 `f[i][k-1] * f[k + 1][j]` 乘积加上 `f[k][k]`

2. 当前的元素的值依赖左和下面的所有的值，所以需要遵循，从下而上，从左至右的顺序来推导

3. 需要注意的一点就是，将 `f[i][i-1]` 初始化为 `1`

```

    | i, k - 1 |  i, j-2  |  i, j-1  |   i, j   |
       |            |         |
       |            |         +------|  i-1, j  |
       |            |
       |            +----------------|  i-2, j  |
       |
       +-----------------------------|  k+1, j  |

```

#### DP coding

```cpp

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

```