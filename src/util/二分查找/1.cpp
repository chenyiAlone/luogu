#include <iostream>
using namespace std;
int nums[] = {0, 3, 3, 3, 5};
int target = 3;
int binary_search_left(int len) {
    int l = 0, r = len - 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (nums[mid] < target) 
            l = mid + 1;
        else 
            r = mid - 1;
    }
    // return (l != len && nums[l] == target ? l : -1);
    return l;
}

int binary_search_right(int len) {
    int l = 0, r = len - 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (target < nums[mid]) 
            r = mid - 1;
        else 
            l = mid + 1;
    }
    // return (r != -1 && nums[r] == target ? r : -1);
    // return (r != -1 ? r : -1);
    return r;
}

int main() {
    int len = sizeof(nums) / sizeof(int);
    cout << "left: " << binary_search_left(len) << endl;
    cout << "right: " << binary_search_right(len) << endl;
    return 0;
}