/*

题目描述
输入N(N<=10000)，验证4~N所有偶数是否符合哥德巴赫猜想。

（N为偶数）。

如果一个数，例如10，则输出第一个加数相比其他解法最小的方案。如10=3+7=5+5，则10=5+5是错误答案。

输入输出格式
输入格式：
第一行N

输出格式：
4=2+2 6=3+3 …… N=x+y

输入输出样例
输入样例#1： 
10
输出样例#1： 
4=2+2
6=3+3
8=3+5
10=3+7


思路:
    1. 线性筛素数
    2. 边界问题，size = 10000 的数组不代表数组的最大值为 1000，最后更新的下标才为小于 size 的最大元素 


*/


#include <iostream>
#define SIZE 10001
using namespace std;

int main() {
    int check[SIZE] = {0};
    int prime[SIZE] = {0};
    int pos=0;
    int flag;
    for (int i = 2 ; i < SIZE ; i++) {
        if (!check[i])
            prime[pos++] = i;

        for (int j = 0 ; j < pos && i*prime[j] < SIZE ; j++) {
            check[i*prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
    int target;
    cin >> target;
    // for (int i = 4; i <= target; i += 2) {
    //     bool found = false;
    //     for (int j = 0; j < pos && !found; j++) {
    //         int t = i - prime[j];
    //         for (int l = 0, r = pos - 1; l <= r; ) {
    //             int mid = (l + r) >> 1;
    //             if (prime[mid] < t)
    //                 l = mid + 1;
    //             else if (t < prime[mid])
    //                 r = mid - 1;
    //             else {
    //                 cout << i << '=' << prime[j] << '+' << prime[mid] << endl;
    //                 found = true;
    //                 break;
    //             }
    //         }
    //     }
    // }
    for (int i = 4; i <= target; i += 2) {
        int l = 0, r = pos - 1;
        while (l <= r) {
            while (prime[l] + prime[r] < i) l++;
            while (prime[l] + prime[r] > i) r--;
            if (prime[l] + prime[r] == i) {
                cout << i << '=' << prime[l] << '+' << prime[r] << endl;
                break;
            }
        }
    }
    return 0;
}