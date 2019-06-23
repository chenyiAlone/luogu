# 二分查找


## 核心

二分查找的精髓就是 `bmid` 的落点和 `target` 的位置关系

```
nums[mid] < target

b: lo .......... mid ...... tar_id ........ hi

e: ............. mid lo ... tar_id ........ hi

落在了 target 左边，将左指针 lo，移到 mid + 1 

=>  lo = mid + 1;

```
```
target < nums[mid]

b: lo ......... tar_id ...... mid ......... hi
            
e: lo ......... tar_id ... hi mid ............

落在了 target 右边，将右指针 hi，移到 mid - 1


=> hi = mid - 1;

```

## 变式

二分查找的变式一般为查找最左边的，最右边的，或者插入位置之类的，只需要将下面的两种类型进行稍微的退出判断即可

## 常规二分

```cpp
    int l = 0, r = len - 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (nums[mid] < target)
            l = mid + 1;
        else if (target < nums[mid])
            r = mid - 1;
        else
            return mid;

    }
    return -1;

```

## 查找最左边的 key （第一个大于等于 target 的位置）

1. `l` 的移动条件是 `nums[mid] < target` 对应 `nums[mid] .. target` 这种情况，小于 `target` 才会更新
2. `r` 的移动条件是 `target <= nums[mid]` 对应在 `target` 右边或者是直接命中的情况，大于等于 `target` 才会更新


```cpp

    int l = 0, r = len - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (nums[mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }
    cout << l;

```

## 查找最右边的 key （第一个小于等于 target 的位置）

1. `r` 的移动条件是 `target < nums[mid]` 对应 `target .. nums[mid]` 这种情况，大于 `target` 才会更新
2. `l` 的移动条件是 `nums[mid] <= target` 对应在 `target` 左边或者直接命中的情况，小于等于 `target` 才会更新

```cpp

    int l = 0, r = len - 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (target < nums[mid])
            r = mid - 1;
        else
            l = mid + 1;
    }
    cout << r;

```