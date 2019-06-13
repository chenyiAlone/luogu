### 行数

> 一共有 `2 * k + 3` 行

### 分析

1. 第 `0, k + 1, 2 * k + 2` 行和其他的行分为两类处理
2. `sel` 代表选择哪一种位置的 `char`

**图示**

```

     0
     -- 
  1 |  | 2
    |  |
    3--  
    |  |
  4 |  | 5
     -- 
     6

```
### 代码

```cpp

#include <iostream>
using namespace std;
                    // 0  1  2  3  4  5  6
                    // -  |  |  -  |  |  -
char nums[10][7] = { {'-', '|', '|', ' ', '|', '|', '-'},
                    {' ', ' ', '|', ' ', ' ', '|', ' '},
                    {'-', ' ', '|', '-', '|', ' ', '-'},
                    {'-', ' ', '|', '-', ' ', '|', '-'},
                    {' ', '|', '|', '-', ' ', '|', ' '},
                    {'-', '|', ' ', '-', ' ', '|', '-'},
                    {'-', '|', ' ', '-', '|', '|', '-'},
                    {'-', ' ', '|', ' ', ' ', '|', ' '},
                    {'-', '|', '|', '-', '|', '|', '-'},
                    {'-', '|', '|', '-', ' ', '|', '-'} };

int main() {
    int k;
    string s;
    cin >> k >> s;
    int len = s.size(), sel;
    for (int i = 0; i < 2 * k + 3; i++) {
        if      (i == 0)         sel = 0;
        else if (i < k + 1)      sel = 1;
        else if (i == k + 1)     sel = 3;
        else if (i < 2 * k + 2 ) sel = 4;
        else                     sel = 6;

        for (int j = 0; j < len; j++) {
            int n = s[j] - '0';
            if (sel == 0 || sel == 3 || sel == 6) {
                cout << ' ';
                for (int t = 0; t < k; t++)
                    cout << nums[n][sel];
                cout << ' ';
            } else {
                cout << nums[n][sel];
                for (int t = 0; t < k; t++)
                    cout << ' ';
                cout << nums[n][sel + 1];
            }
            cout << ((j == len - 1) ? '\n' : ' '); 
        }
    }
    return 0;
}

```