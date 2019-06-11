### 时间复杂度

这套题目正正卡了我两天的时间，以至于最后颤颤巍巍交上去的时候我都不觉得能过。

#### 思路

1. 处理 `F i x y` 中的 `x-y` ，根据他们的大小关系，返回单个 `For` 的复杂度

    - `-1`:  不执行循环，使用 `unrun` 将内部的循环强行清零
    - `0` :  常数次的循环
    - `1` :  `n` 次的循环

2. `error` 来保存错误状态，`used[26]` 检验是否在嵌套循环中重复使用相同变量，`degree` 用于累计所有 `for` 的级别，`w` 保存最大的值。

3. 跳过不执行的循环情况（`l > r`）。 `unrun = -1` 代表记录了 `cnt` 的级别，这期间所有的级别都置为 `0` 加到 `degree` 中，当出现的 `E` 减到的 `cnt == unrun - 1` 的值时，证明已经完成了内部所有的循环，`unrun = -1;` 重置

##### check(l, r) 
```cpp

int check(string &s1, string &s2) {
    // -1： 不执行， 0： 常数， 1： n
    if (s1.compare("n") == 0) { // n, ?
        if (s2.compare("n") == 0) { // n, n
            return 0;
        } else { // n, 9
            return -1;
        }
    } else {    // 9, ?
        if (s2.compare("n") == 0) { // 9, n
            return 1;
        } else { // 9, 9 
            // 常数
            int a = atoi( s1.c_str() );
            int b = atoi( s2.c_str() );
            if (a > b) {
                return -1;
            } else {
                return 0;
            }
        }
    }
}

```