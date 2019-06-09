### 最开始的思路

    每次不够都直接从右边相邻的元素中获取，将多余的转移到下一个元素

#### 过程

1. 求出当前的元素相对于 ave 分摊后的值的差 part
2. part != 0 && i + 1 != n，res++，cards[i + 1] += part;

```cpp
    for (int i = 0; i < n; i++) {
        int part =   cards[i] - ave;
        if (part != 0 && i + 1 < n) {
            cards[i + 1] += part;
            res++;
        }
    }

```


```cpp

    for (int i = 0; i < n; i++) {
        int part = cards[i] - ave;
        if (cards[i] - ave > 0) {
            if (i + 1 < n) {
                cards[i + 1] += part;
                res++;
            }
            // last += part;
        } else if (part == 0) {

        } else {
            if (i + 1 < n) {
                cards[i + 1] += part;
                res++;
            }
        }
        cards[i] = ave;
    }

```