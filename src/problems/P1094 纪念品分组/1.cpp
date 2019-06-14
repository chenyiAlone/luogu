/*

题目描述
元旦快到了，校学生会让乐乐负责新年晚会的纪念品发放工作。为使得参加晚会的同学所获得 的纪念品价值相对均衡，他要把购来的纪念品根据价格进行分组，但每组最多只能包括两件纪念品， 并且每组纪念品的价格之和不能超过一个给定的整数。为了保证在尽量短的时间内发完所有纪念品，乐乐希望分组的数目最少。

你的任务是写一个程序，找出所有分组方案中分组数最少的一种，输出最少的分组数目。

输入输出格式
输入格式：
共n+2n+2行:

第11行包括一个整数ww，为每组纪念品价格之和的上上限。

第22行为一个整数nn，表示购来的纪念品的总件数GG。

第33至n+2n+2行每行包含一个正整数P_i(5 \le P_i \le w)P 
i
​	 (5≤P 
i
​	 ≤w)表示所对应纪念品的价格。

输出格式：
一个整数，即最少的分组数目。

输入输出样例
输入样例#1： 
100 
9 
90 
20 
20 
30 
50 
60 
70 
80 
90
输出样例#1： 
6
说明
50％的数据满足：1 \le n \le 151≤n≤15
100％的数据满足：1 \le n \le 30000,80 \le w \le 2001≤n≤30000,80≤w≤200

思路:
    1. 优先使用小的凑大的和大小配对的结果是相同的

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int w, n;
    cin >> w >> n;
    vector<int> mementos(n);
    for (int i = 0; i < n; i++)
        cin >> mementos[i];
    sort(mementos.begin(), mementos.end());
    int l = 0, r = n - 1, res = 1;
    while (l < r) {
        if (mementos[l] + mementos[r] > w) {
            res++;
            r--;
        } else {
            mementos[r] += mementos[l];
            l++;
        }
    }
    cout << (n == 0 ? 0 : res);
    return 0;
}