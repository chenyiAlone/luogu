## 八皇后

### 普通的做法

#### 可放置判断

前提条件：所有已经放置的 `quen` 和当前位置不在同一条直线或者对角线上

```
f[i][j] == quen
```

|     附加条件     |  位置  |
|:---------------:|:------:|
|`    j == y    ` |   `|`  |
|`i + j == x + y` |   `/`  |
|`i + y == x + j` |   `\`  |


### 位运算八皇后问题

1. `a, b, c` 三个数来分别对应 `/, |, \` 三种冲突
2. `d = ~(a | b | c)` 得到的就是排除掉所有冲突后剩下的可行位置
3. `bit = d & -d` 每次取最后一个 `1` 尝试
4. `b == 125` 也就是所有的位都为 `1` ，即每一行都填上了一个皇后便是答案

#### unsigned char 经典八皇 coding

```cpp

void dfs(unsigned char a, unsigned char b, unsigned char c) {
    if (b == 125) {
        cnt++;
        return;
    }
    unsigned char d = ~(a | b | c);
    while (d) {
        unsigned char bit = d & -d;
        dfs((a | bit) << 1, b | bit, (c | bit) >> 1);
        d -= bit;
    }
}

```

### 位运算 N 皇后问题（原来思路）

1. 使用了 `unsigned char` 只能用来解决八皇后的问题，使用 `unsigned int` 将其升级到最高 `32 x 32` 的棋盘

2. 需要注意的三个地方就是:

    1. `while (d)` 的边界问题。
        - `d = ~(a | b | c)` 需要 `d` 中确保全闲置位置部为 `1`，所以后 `n` 位全部为 `0` 的时候，就是 `d` 的最小边界(不包含，类似于 `0`),也就是八皇后时的边界：`11111111....1 | 00000000` 

        - `board = (~0 >> n) << n`

    2. 下层 `dfs()` 时 `a` 的问题。
        - 在 `unsigned char` 中，对于多余的左移，会直接溢出(`c` 的右移同理)，但是 `unsigned int` 中，`n < 32` 的情况中，左移会移动到闲置位置上将其置为 `1`，这些位置必须保持为 `0` 不变。，使用 `<<` 将移位后闲置多余的 `1` 移除即可.置于 `c` 因为是右移，不影响闲置位置，所以不用处理
        
        - `ma = ((a | bit) << (32 - n)) >> (32 - n)`

    3. `b` 的值，循环结束条件。
        - 在八皇后问题中，`b = 125` 便是结果，但是在 `N` 皇后问题中，需要的就是后 `n` 位全部为 `1`，由此便可以得知其最终的边界 `00000...0 | 11111111`

        - `b == (1 << n) - 1`

3. 如何获得每一位的位置？`bit` 是选择的位置的 `bit = 2 ^ i`，因此求出对应的 `i` 即可


```cpp
    int cal_i(int x) {
        int ret = 0;
        while (x) {
            x >>= 1;
            ret++;
        }
        return ret;
    }

```
### 位运算 N 皇后问题再改进

让 `d` 只保留有效的 `n` 位即可，不需要对 `while` 边界处理

```cpp

    int d = ~(a | b | c) & ((1 << n) - 1);
    ...
        dfs((a | bit) >> 1, b | bit, (c | bit) >> 1);
    ...
}

```

#### unsigned int N 皇后 coding

```cpp

void dfs(unsigned int a, unsigned int b, unsigned int c) {
    if (b == (1 << n) - 1) {
        cnt++;
        return;
    }
    int d = ~(a | b | c) & ((1 << n) - 1);
    while (d) {
        int bit = d & -d;
        dfs((a | bit) >> 1, b | bit, (c | bit) >> 1);
        d -= bit;
    }
}

```