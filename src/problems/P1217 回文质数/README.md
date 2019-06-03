### 1.构建回文数-> 2.判断是否为素数

	思路是先构造回文数，然后判断这个数的否为素数

题目给的范围很大，所有如果使用暴力的方法肯定是超时，因为对那个筛素数不是很熟，所以想用先构造回文数，再判断是否正确的方式来节省一定的时间，毕竟所有的偶数除去，少了一大半，然后又是回文数，所以剩下的数并不是很多。

------

`build(int l, int r, int cnt, int len)`方法用于生成回文数
> 其中的 `l` 为最高位的下标，`r` 为最低位下标，`cnt` 用于统计当前已经构造了多少位，每一位构造的时候只需要使用这一位的下标然后进行枚举 `j` 在指定范围内 `pow(10, index) * j` 加到 `sum` 即可，这样从两头向中间，对应的两个位置枚举相同的数即可。

-----
**几个特殊条件：**

1. 长度为 `1` 的时候，从 `5` 开始，`int j = (len == 1 ? 5 : (r == 0 ? 1 : 0));`
2. 不能越界 `lboard <= sum <= rboard`,`if (sum + temp > rboard) break;` 和 `if (sum >= lboard && cnt == 0 && isPrime(sum))`
3. `len` 为奇数的时候,最后 `l` 和 `r` 会正好相等，只加其中一个
```
if (l == r) {
	temp = (int)pow(10, r) * j;
} else {
	temp = (int)pow(10, l) * j + (int)pow(10, r) * j;
}
```
#### 源码

```cpp
#include <iostream>
#include <math.h>

using namespace std;

int lboard, rboard;

// 判断是否为素数
bool isPrime(int n) {
    for (int i = 2; i <= (int)sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

// 构建回文数
void build(int l, int r, int sum, int cnt, int len) {
    if (l < r || cnt <= 0) {
        if (sum >= lboard && cnt == 0 && isPrime(sum))
            cout << sum << endl; 
        return;
    }
    for (int j = (len == 1 ? 5 : (r == 0 ? 1 : 0)); j <= 9; j += (r == 0 ? 2 : 1)) {
        int temp = 0;
        if (l == r) {
            temp = (int)pow(10, r) * j;
        } else {
            temp = (int)pow(10, l) * j + (int)pow(10, r) * j;
        }
        if (sum + temp > rboard)
            break;
        build(l -1, r + 1, sum + temp, cnt - (l == r ? 1 : 2), len);
    }
}

// 求给定数的长度
int len(int n) {
    int ret = 0;
    while (n > 0) {
        ret++;
        n /= 10;
    }
    return ret;
}

int main() {
    
    cin >> lboard >> rboard;
    int llen = len(lboard), rlen = len(rboard);

    for (int i = llen - 1; i < rlen; i++) {
        build(i, 0, 0, i + 1, i + 1);
    }
    return 0;
}
```