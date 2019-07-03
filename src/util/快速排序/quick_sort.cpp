#include <iostream>
using namespace std;

void print_arr(int arr[], int len) {
    for (int i = 0; i < len; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

void sort(int l, int r, int arr[]) {
    if (l >= r) return;
    int base = arr[l + rand() % (r - l + 1)];
    int L = l, R = r;
    while (L <= R) {
        while (L <= R && arr[L] < base) L++;
        while (L <= R && arr[R] > base) R--;
        if (L <= R)  {
            swap(arr[L], arr[R]);
            L++;    R--;
        }
    }
    sort(l, R, arr);
    sort(L, r, arr);
}

void quick_sort(int arr[], int len) {
    sort(0, len - 1, arr);
}


int main() {
    int arr[] = {3, 2, 1, 5, 0};
    int len = sizeof(arr) / sizeof(int);
    cout << len << endl;
    quick_sort(arr, len);
    print_arr(arr, len);
    return 0;
}