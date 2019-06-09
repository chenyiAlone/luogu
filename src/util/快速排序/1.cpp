#include <iostream>
#include <vector>
using namespace std;

void print_array(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << ' ';
    }
    cout << endl;
}

// 选择 nums[lo]、nums[mid]、nums[hi] 三个数种的中位数作为中轴，将中轴藏到 hi - 1 的位置上
// nums[lo] <= nums[hi - 1] <= nums[hi]
int get_pivot(int lo, int hi, vector<int> &nums) {
    int mid = (lo + hi) >> 1;
    if (nums[lo] > nums[mid]) swap(nums[lo], nums[mid]);
    if (nums[mid] > nums[hi]) swap(nums[mid], nums[hi]);
    if (nums[lo] > nums[mid]) swap(nums[lo], nums[mid]);
    swap(nums[mid], nums[hi - 1]);
    cout << "nums[lo]: " << nums[lo] << ", nums[mid]: " << nums[mid] << ", nums[hi]: " << nums[hi] << endl;
    return nums[hi - 1];
}

// 使用 ++l 来完成从 lo + 1 到 hi - 2 之间的交换
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

void quick_sort(vector<int> &nums) {
    sort(0, (int)nums.size() - 1, nums);
}

int main() {
    vector<int> nums = {4, 2, 4, 5, 1};

    quick_sort(nums);
    print_array(nums);
    return 0;
}
