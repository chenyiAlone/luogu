/*

题目描述
设有nn个正整数(n≤20)(n≤20)，将它们联接成一排，组成一个最大的多位整数。

例如：n=3n=3时，33个整数1313,312312,343343联接成的最大整数为：3433121334331213
又如：n=4n=4时，44个整数77,1313,44,246246联接成的最大整数为：74246137424613
输入输出格式
输入格式：
第一行，一个正整数nn。

第二行，nn个正整数。

输出格式：
一个正整数，表示最大的整数

输入输出样例
输入样例#1： 
3
13 312 343
输出样例#1： 
34331213


思路:
    只需要按照对长度取模的降序排列即可


*/
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(string &str1, string &str2) {
    for (int i = 0; i < max(str1.size(), str2.size()); i++) {
        int id1 = i % str1.size(), id2 = i % str2.size();
        if (str1[id1] != str2[id2]) return str1[id1] > str2[id2];
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    string strs[n] = {};
    for (int i = 0; i < n; i++) 
        cin >> strs[i];
    sort(strs, strs + n, cmp);
    for (int i = 0; i < n; i++)
        cout << strs[i];
    return 0;
}