#include <iostream>
#include <vector>
using namespace std;

void quickSort(int lo, int hi, vector<int> &nums) {
    if (lo >= hi) return;
    // int lt = lo, gt = hi, i = lo + 1;
    // while (i <= gt) {
    //     if (nums[i] < nums[lo]) swap(nums[i++], nums[lt++]);
    //     else if (nums[i] > nums[lo]) swap(nums[i], nums[gt--]);
    //     else i++;
    // }
    
    int l = lo, r = hi, pivot = nums[(lo + hi) >> 1];
    while (l <= r) {
        while (nums[l] < pivot) ++l;
        while (nums[r] > pivot) --r;
        if (l < r) {
            swap(nums[l], nums[r]);
            l++;
            r--;
        } else if (l == r)
            ++l;
    }
    // swap(nums[lo], nums[r]);


    quickSort(lo, r, nums);
    quickSort(l, hi, nums);
    // int mid = (l + r) >> 1;
}


int main() {
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    quickSort(0, (int)nums.size() - 1, nums);
    // swap(nums[1], nums[2]);
    // cout << nums.size();
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << (i + 1 == nums.size() ? "" : " ");
    cout << endl;
    return 0;
}