## KMP

### next[]

1. 以自身为模式串，初始化 `i = 0, j = -1` 相当于右移了一位
2. 特别重要的是这里的边界，因为 `i, j` 都执行自加运算再赋值，所以 `i < len - 1`
3. 匹配的情况为 `j == -1 || s[i] == s[j]` 的时候，`i++, j++, next[i] = j`
4. 失配的情况 `j = next[j]`


```cpp

    void getNext(string s, int next[]) {
        int len = s.size();
        next[0] = -1;
        int i = 0, j = -1;
        while (i < len - 1) {
            if (j == -1 || s[i] == s[j]) {
                i++;    j++;
                next[i] = j;
            } else
                j = next[j];
        }
    }

```

### kmp core

1. 初始化 `i = 0, j = 0`
2. 匹配则 `i++, j++`
3. 失配则 `j = next[j]`
3. 当 `j` 到达了结尾，就说明了 `i - j` 位置就是匹配的起点


```cpp

    int kmp(string s, string t, int next[]) {
        int slen = s.size(), i = 0; // 文本串
        int tlen = t.size(), j = 0; // 模式串
        while (i < slen && j < tlen) {
            if (j == - 1 || s[i] == t[j]) 
                i++;    j++;
            else
                j = next[j];
        }
        if (j == tlen)
            return i - j;
        else
            return -1;
    }

```

