## 树状数组

### 简介

1. 树状数组用于求区间和，可以进行修改元素的值更新区间，每次可以修改一个元素
2. 想要更新一个元素，只需要 add(id, newValue - oldValue) 即可

### int lowbit(int t)

```cpp
int lowbit(int t) {
    return t&(-t);
}

```

### void add(int id, int x)

```cpp

    void add(int id, int x) {
        for (int i = id; i <= len; i += (i & -i)) {
            sum[i] += x;
        }
    }

```

### int get(int id)

```cpp

    int get_sum(int id) {
        int ret = 0;
        for (int i = id; i > 0; i -= (i & -i)) {
            ret += sum[i];
        }
        return ret;
    }

```
