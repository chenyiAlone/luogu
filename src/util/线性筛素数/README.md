### 线性筛素数

1. 从 `2` 开始
2. 每次将所有的素数和 `i` 的乘积构成的合数全部筛掉 ( `prime[j] * i < size` )
3. 剩下的就是 `2 - size` 中间的 `pos` 个素数

```cpp

    for (int i = 2 ; i < SIZE ; i++) {
        if (!iscom[i])  // 不是合数，也就是质素，添加到 prime[] 中
            prime[pos++] = i;

        for (int j = 0 ; j < pos && i * prime[j] < SIZE ; j++) {
            iscom[i * prime[j]] = 1;  // 筛掉 *已经筛选* 出来的质数和 i 的乘积小于 size 的所有合数
            if (i % prime[j] == 0)
                break;
        }
    }
```