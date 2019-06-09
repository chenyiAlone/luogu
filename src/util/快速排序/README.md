### 快速排序

#### 中轴的选择

1. 选择 `nums[lo]`、 `nums[mid]`、 `nums[hi]` 三个数中的中位数
2. 三个数排序后，`nums[mid]` 的值就是最后要得到的 `pivot`
3. 将 `nums[mid]` 藏到 `hi - 1` 的位置上，从而 `nums[lo] <= nums[hi - 1] <= nums[hi]`
4. `pivot` 即 `nums[hi - 1]` 的值


#### 快排核心

1. 通过轴心的选择，已经确定了 `nums[lo]` `nums[hi - 1]` 和 `nums[hi]` 三个的值相对于 `pivot` 的大小关系

2. **只需要关心 `nums[lo + 1] ~ nums[hi - 2]` 即可**

3. 最后 `l` 的位置是 `pivot` 的位置，完成 `l`、`r` 的交换后，将 `pivot` 归位

```cpp

void sort(int lo, int hi, vector<int> &nums) {
    if (lo >= hi) return;
    int pivot = get_pivot(lo, hi, nums);
    print_array(nums);
    int l = lo, r = hi - 1;
    while (l < r) {
        while (nums[++l] < pivot);
        while (nums[--r] > pivot);
        if (l < r) swap(nums[l], nums[r]);
    }
    swap(nums[l], nums[hi - 1]);
    sort(lo, l - 1, nums);
    sort(l + 1, hi, nums);
}

```

