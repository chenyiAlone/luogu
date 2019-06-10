### p1 的处理

`p1 == 2` 的时候只处理 `j` 为小写字母的情况

#### 化简

```cpp

temp += p1 == 3 ? '*' : (p1 == 2 && 'a' <= j && j <= 'z' ? j - 32 : j);

```

#### 原版

```cpp
if (p1 == 3) 
    temp += '*';
else if (p1 == 2 && isAlphabte(j)) 
    temp += j -32;
else 
    temp += j;

```