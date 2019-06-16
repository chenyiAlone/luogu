## 回溯

    在回溯中的标记已经遍历的元素时，总是不知道怎么写，就在这里总结一下

#### 进入前标记，退出后取消

- 优点
    - 不容易忘掉取消标记，对于退出情况比较复杂的情况，也不受影响

- 缺点
    - 特殊条件调用时可能写起来复杂

```cpp

// 调用相对繁琐
trace[i] = true;
dfs(i);
trace[i] = false;

// 返回条件简单
void dfs(int index) {
    if (index == n) 
        return;
    for (int i = 0; i < n; i++) {
        if (!trace[i]) {
            trace[i] = true;
            dfs(i);
            trace[i] = false;
        }
    }
}

```

#### 进入后标记，退出前取消

- 优点
    - 调用简单

- 缺点
    - 返回语句书写顺序不能出错

```cpp

// 调用简单
dfs(i);

// 返回如果放在了标记后面就错了，容易出现问题
void dfs(int index) {
    if (index == n)
        return;
    trace[index] = true;
    for (int i = 0; i < n; i++)
        if (!trace[i])
            dfs(i);
    trace[index] = false;
}

```