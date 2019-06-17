## 广度优先搜索

### 优点

1. 可以求出最短路径
2. 不会爆炸

### 缺点

1. 无法记录路径

### queue<E>

```cpp

    for ( ; que.size() > 0; que.pop()) {
        E e = que.front();
        que.push(e.a);
    }

```


| return type |  method  |
|:-----------:|:--------:|
|     E       |  front() |
|    void     |   pop()  |
|    bool     |  empty() |
