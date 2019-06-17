## 深度优先搜索 DFS

### 优点 

1. 书写简单
2. 可以记录路径

### 缺点

1. 可能会爆栈


### 搜索顺序

1. 按照题目的运行顺序进行搜索
2. 比如这个题目中需要对所有的字母赋值，虽然字母个数唯一，但搜索顺序影响剪枝的效果
3. 将 `A B C D E` 转化为 `D E A C B`的顺序进行搜索

```
    ABCED
    BDACE
    EBBAA

```

### 剪枝

1. 对于搜索的要求度很高，数据量大，可以使用剪枝
2. 中断已经不满足后需要求的搜索

```cpp

    bool can_prune() {
        if (can prune) return true;
        return false;
    }

    void dfs() {
        if (can_prune()) return;

    }

```
