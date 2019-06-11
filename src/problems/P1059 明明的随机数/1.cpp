/*

题目描述
明明想在学校中请一些同学一起做一项问卷调查，为了实验的客观性，他先用计算机生成了NN个11到10001000之间的随机整数(N≤100)(N≤100)，对于其中重复的数字，只保留一个，把其余相同的数去掉，不同的数对应着不同的学生的学号。然后再把这些数从小到大排序，按照排好的顺序去找同学做调查。请你协助明明完成“去重”与“排序”的工作。

输入输出格式
输入格式：
输入有两行，第11行为11个正整数，表示所生成的随机数的个数NN
第22行有NN个用空格隔开的正整数，为所产生的随机数。

输出格式：
输出也是两行，第11行为11个正整数MM，表示不相同的随机数的个数。

第22行为MM个用空格隔开的正整数，为从小到大排好序的不相同的随机数。

输入输出样例
输入样例#1： 
10
20 40 32 67 40 20 89 300 400 15
输出样例#1： 
8
15 20 32 40 67 89 300 400


思路:
    快排，然后去重

*/
#include <iostream>
#include <vector>
using namespace std;
int f[100];
int n;

void sort(int lboard, int rboard) {
    if (lboard >= rboard)
        return;
    int mid = (lboard + rboard) >> 1;
    if (f[lboard] > f[mid]) swap(f[mid], f[lboard]);
    if (f[mid] > f[rboard]) swap(f[mid], f[rboard]);
    if (f[lboard] > f[mid]) swap(f[lboard], f[mid]);
    // cout << f[lboard] << ' ' << f[mid] << ' ' << f[rboard] << endl;
    swap(f[mid], f[rboard - 1]);
    int axis = f[rboard - 1];
    // cout << "axis: " << axis << endl; 
    int l = lboard, r = rboard - 1;
    while (l < r) {
        while (f[++l] < axis);
        while (f[--r] > axis);
        if (l < r) swap(f[l], f[r]);
    }
    swap(f[l], f[rboard -1]);
    // for (int i = 0; i < n; i++) 
    //     cout << f[i] << ' ';
    //     cout << endl;
    // cout << l << endl;
    sort(lboard, l - 1);
    sort(l + 1, rboard);
}


int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> f[i];
    sort(0, n - 1);
    int len = 0;
    vector<int> res;
    for (int i = 0; i < n; i++) {
        if (len == 0 || f[i] != res[len - 1]) {
            res.push_back(f[i]);
            len++;
        }
    }
    cout << len << endl;
    for (int i = 0; i < len; i++)
        cout << res[i] << ' ';
    return 0;
}