### 所有的移动状态

**限定条件**

1. 数组朝向我为 `0`，反之为 `1`
2. 向左为 `0`，向右为 `1`
3. 条件关联 `toy.first ^ a`

------

**移动方向**

| toy.first |     a     |    mov   |
|:---------:|:---------:|:--------:|
|     0     |     0     |     +    |
|     0     |     1     |     -    |
|     1     |     1     |     +    |
|     1     |     0     |     -    |


### 边界简化
**优化版**

```cpp
    int mov = ((toys[index].first ^ a) ? b : -b) % n;
    index = (index + mov + (-mov > index ? n : 0)) % n;
```
----

**原始版**

```cpp
    int mov = ((toys[index].first ^ a) ? b : -b) % n;
    int target = abs((index + mov) % n);
    if (mov > 0) {
        index = (index + mov) % n;
    } else {
        if (-mov > index) {
            index = n + index + mov;
        } else {
            index = index + mov;
        }
    }
```