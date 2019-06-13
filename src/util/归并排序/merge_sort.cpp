#include <iostream>
using namespace std;

void merge(int l, int r, int *nums, int *temp) {
    if (l == r) return;
    int mid = (l + r) >> 1;
    merge(l, mid, nums, temp);
    merge(mid + 1, r, nums, temp);
    for (int i = l; i <= r; i++) {
        temp[i] = nums[i];
    }
    for (int i = l, j = mid + 1, index = l; i <= mid; index++) {
        if (j == r + 1 || temp[i] < temp[j]) {
            nums[index] = temp[i++];
        } else {
            nums[index] = temp[j++];
        }
    }
}

void merge_sort(int *nums, int len) {
    int temp[len] = {};
    merge(0, len - 1, nums, temp);
}

int main() {
    int nums[] = {2, 3, 1, 5, 4};
    int len = sizeof(nums) / sizeof(int);
    cout << "len: " << len << endl;
    merge_sort(nums, len);
    for (auto x : nums)
        cout << x << ' ';
    return 0;
}
