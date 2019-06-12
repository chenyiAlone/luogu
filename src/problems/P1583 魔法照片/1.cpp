/*

题目描述
一共有n（n≤20000）个人（以1--n编号）向佳佳要照片，而佳佳只能把照片给其中的k个人。佳佳按照与他们的关系好坏的程度给每个人赋予了一个初始权值W[i]。然后将初始权值从大到小进行排序，每人就有了一个序号D[i]（取值同样是1--n）。按照这个序号对10取模的值将这些人分为10类。也就是说定义每个人的类别序号C[i]的值为(D[i]-1) mod 10 +1，显然类别序号的取值为1--10。第i类的人将会额外得到E[i]的权值。你需要做的就是求出加上额外权值以后，最终的权值最大的k个人，并输出他们的编号。在排序中，如果两人的W[i]相同，编号小的优先。

输入输出格式
输入格式：
第一行输入用空格隔开的两个整数，分别是n和k。

第二行给出了10个正整数，分别是E[1]到E[10]。

第三行给出了n个正整数，第i个数表示编号为i的人的权值W[i]。

输出格式：
只需输出一行用空格隔开的k个整数，分别表示最终的W[i]从高到低的人的编号。

输入输出样例
输入样例#1： 
10 10
1 2 3 4 5 6 7 8 9 10
2 4 6 8 10 12 14 16 18 20
输出样例#1： 
10 9 8 7 6 5 4 3 2 1


思路:
    意识到了审题的重要性，下次我一定好好读题再做题
    1. 序号是不变的，第二次排序只是根据一次排序的 D[i] 
    2. 实际比较的时候还是用的输入顺序的序号

*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp1(const pair<int, int> &per1, const pair<int, int> &per2) {
    if (per1.second != per2.second) 
        return per1.second > per2.second;
    return per1.first < per2.first;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector< pair<int, int> > persons(n);
    vector<int> e(10, 0);
    for (int i = 0; i < 10; i++) {
        cin >> e[i];
    }
    for (int i = 0; i < n; i++) {
        persons[i].first = i + 1;
        cin >> persons[i].second;
    }
    sort(persons.begin(), persons.end(), cmp1);
    for (int i = 0; i < n; i++) {
        persons[i].second += e[i % 10];
    }
    sort(persons.begin(), persons.end(), cmp1);
    for (int i = 0; i < k; i++) 
        cout << persons[i].first << (i + 1 == k ? "" : " ");
    return 0;
}