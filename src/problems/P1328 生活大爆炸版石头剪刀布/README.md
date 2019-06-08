#### 通过最小公倍数来简化掉重复运算


```cpp
int enda = 0, endb = 0;
    int mcm = minCommonMultiple(a, b);
    int times = n / mcm;
    int ends = n % mcm;
    // cout << mcm << ' ' << times << ' ' << ends << endl;
    for (int i = 0; i < ((times > 0) ? mcm : n); i++) {
        if (i == ends - 1) { // 最后一轮的次数
            enda = wa;
            endb = wb;
        }
    }
    // cout << wa << ' ' << wb << ' ' << enda << ' ' << endb << endl;
    wa = wa * times + enda;
    wb = wb * times + endb;

```

##### 计算最小公倍数，最小公约数的方法

```cpp
int maxCommonDivisor(int m, int n) {  
    if (m < n) {     // 保证被除数大于除数
        int temp = m;  
        m = n;  
        n = temp;  
    }  
    while (m % n != 0) {  // 在余数不能为0时,进行循环  
        int temp = m % n;  
        m = n;  
        n = temp;  
    }  
    return n;    // 返回最大公约数  
}  

int minCommonMultiple(int m, int n) {  
    return m * n / maxCommonDivisor(m, n);  
} 
```