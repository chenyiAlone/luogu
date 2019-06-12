### 归并排序

#### 流程

1. 将 `l ~ r` 的数复制到 `temp[]` 中
2. 归并到 `nums` 

#### 重点

1. 边界处理

```cpp

    1. if (l == r) return; // 一个元素退出

    2. merger(   l   , mid);    //     l   ~ mid
       merger(mid + 1,  r );    // mid + 1 ~  r

    3. for (int i = l; i <= r; i++) // 同样为 l
            temp[i] = nums[i];

    4. index = l    // temp 起始也为 index


```
2. 归并

因为前面已经将`nums` 全部拷贝到了 `temp` ，所以归并的时候，只关注左半边的剩余情况，如果右边的并未执行完毕，证明左边的最大的元素小于剩下的右边元素中的最小元素， 而左右子序列已经是有序的，不用再经行处理

```cpp
    // i j
    for (int i = l, j = mid, index = 0; i <= mid; index++) {
        if (j == r + 1 || temp[i] < temp[j]) {
            nums[index] = temp[i++];
        } else {
            nums[index] = temp[j++];
        }
    }

```

