### 知识点

1. 对象传递的时候使用引用 `&`
2. 

### 头文件

|            method          |    head    |
|:--------------------------:|:----------:|
| accumulate(&begin, &end, 0)|   numeric  |
| memset(&arr, 0, sizeof(ar))|   string   |


### struct

**`typedef struct`** 关键字

```cpp
    typedef struct {
        int id;
        int sorce;
        int value;
    } player;

    player p;

```


### array init

1. 初始化为 `0`，结构体同理
```cpp

    int f[199] ={};

```

### string

1. `str1.compare(str2)` 相等的时候返回的是 `0`, `==` 可以用于用于字符串的比较

```cpp
    string a("11"), b("11"), c("1");
    cout << "cmp(a, b): " << cmp(a, b) << endl;
    cout << "cmp(b, c): " << cmp(b, c) << endl;
    cout << "a == b: " << (a == b) << endl;
    cout << "a == c: " << (a == c) << endl; 
    /*--------------- output ---------------*/
    a.compare(b): 0
    a.compare(c): 1
    a == b: 1
    a == c: 0

```

2. `to_string()` 将 `int` 转 `string` ( c++ 11 )

```cpp

    int w = 10;
    string res;
    res += to_string(w);

```

