# 高精度乘法

## 思路

1. 初始化
    - **`multiplicand[N] = { 1 }`** 储存 **当前的乘积** 
    - **`product[N]`** 储存 **乘积**

2. 在完成每次的乘法运算后，将 `product[N]` 的值转移到 `multiplicand[N]` 中，将 **乘积** 转换为 **被乘数**

3. 乘法运算过程
    - 清空 `product[N]` 保存的 **乘积**
    - `i = len - 1; i >= 0; i++` 从乘数的 **自低位向最高位** 枚举 **乘数** `string num` 每一位
        1. `j = 0; j <= end_index + 1` 枚举 **被乘数**的每一位

        2. `p = len - i - 1` ***p*** 初始化为对应 `mulitplicand` 的起始下标
        3. `cy = 0` 进位初始化为 `0`

        4. `sum = (num[i] - '0') * mulitplicand[p] + cy` 求出 **乘数** `i` 位 `num[i]` 和 **被乘数** `j` 位 `mulitplicand[j]` 的乘积加上 **乘积**的第 `p` 位 `product[p]` 的和 `sum`

        5. `product[p++] = sum % 10` **乘积** 的第 `p` 位更新为 `sum` 的个位的值

        6. `cy = sum / 10` 更新进位(上面的 `end_index + 1` 的范围省去了最后 `cy != 0, product[p] = cy` 的判断)

    - 更新 `end_index`
        1. `end_index += len` ***n*** 位数乘上 ***m*** 位数，乘积的长度肯定小于 `m + n`
        
        2. `while (end_index > 0 && product[end_index] == 0) end_index--;` 更新到正确的位置，为 **0** 的是后为只有 **1** 位

    - `swap(mulitplicand, product)` 将乘积更新为新的 **被乘数**

## Coding

```cpp
#include <iostream>
#include <cstring>
#define N 4006
using namespace std;

int multiplicand[N] = {1}, end_index = 0, product[N];

void mul(string &num) {
    memset(product, 0, sizeof(product));
    int len = num.size();
    for (int i = len - 1; i >= 0; i--) {   // p 为
        int cy = 0, p = len - i - 1;
        for (int j = 0; j <= end_index + 1; j++) {
            int sum = product[p] + (num[i] - '0') * multiplicand[j] + cy;
            product[p++] = sum % 10;
            cy = sum / 10;
        }
    }
    end_index += len;
    while (end_index > 0 && product[end_index] == 0 )   end_index--;
    swap(multiplicand, product);
}

int main() {
    string a, b;
    cin >> a >> b;
    mul(a);
    mul(b);
    for (int i = end_index; i >= 0; i--)
        cout << multiplicand[i];
    cout << endl;
    return 0;
}
```