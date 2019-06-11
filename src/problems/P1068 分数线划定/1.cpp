/*

题目描述
世博会志愿者的选拔工作正在 A 市如火如荼的进行。为了选拔最合适的人才，AA市对所有报名的选手进行了笔试，笔试分数达到面试分数线的选手方可进入面试。面试分数线根据计划录取人数的150\%150%划定，即如果计划录取mm名志愿者，则面试分数线为排名第m \times 150\%m×150%（向下取整）名的选手的分数，而最终进入面试的选手为笔试成绩不低于面试分数线的所有选手。

现在就请你编写程序划定面试分数线，并输出所有进入面试的选手的报名号和笔试成绩。

输入输出格式
输入格式：
第一行，两个整数 n,m(5 ≤ n ≤ 5000,3 ≤ m ≤ n)n,m(5≤n≤5000,3≤m≤n)，中间用一个空格隔开，其中nn表示报名参加笔试的选手总数，mm表示计划录取的志愿者人数。输入数据保证 m \times 150\%m×150%向下取整后小于等于 nn。

第二行到第 n+1n+1 行，每行包括两个整数，中间用一个空格隔开，分别是选手的报名号 k(1000 ≤ k ≤ 9999)k(1000≤k≤9999)和该选手的笔试成绩 s(1 ≤ s ≤ 100)s(1≤s≤100)。数据保证选手的报名号各不相同。

输出格式：
第一行，有22个整数，用一个空格隔开，第一个整数表示面试分数线；第二个整数为进入面试的选手的实际人数。

从第二行开始，每行包含22个整数，中间用一个空格隔开，分别表示进入面试的选手的报名号和笔试成绩，按照笔试成绩从高到低输出，如果成绩相同，则按报名号由小到大的顺序输出。

输入输出样例
输入样例#1： 
6 3 
1000 90 
3239 88 
2390 95 
7231 84 
1005 95 
1001 88
输出样例#1： 
88 5 
1005 95 
2390 95 
1000 90 
1001 88 
3239 88 
说明
【样例说明】

m \times 150\% = 3 \times150\% = 4.5m×150%=3×150%=4.5，向下取整后为44。保证44个人进入面试的分数线为8888，但因为8888有重分，所以所有成绩大于等于8888 的选手都可以进入面试，故最终有55个人进入面试。

NOIP 2009 普及组 第二题

思路:
    需要处理的就是相等的情况，以及将分数线设置成最低的那位同学


*/
#include <iostream>
using namespace std;
int n, m;
int f[5000][2];

int cmp(int *stu1, int *stu2) {
    if (stu1[1] == stu2[1]) {
        return stu1[0] - stu2[0];
    } else {
        return -(stu1[1] - stu2[1]);
    }
}   

void quick_sort(int lb, int rb) {
    if (lb >= rb) return;
    int m = (lb + rb) >> 1;
    if (cmp(f[lb], f[m]) > 0) swap(f[lb], f[m]);
    if (cmp(f[m], f[rb]) > 0) swap(f[m], f[rb]);
    if (cmp(f[lb], f[m]) > 0) swap(f[lb], f[m]);
    swap(f[m], f[rb - 1]);
    int *target = f[rb - 1];
    int l = lb, r = rb - 1;
    while (l < r) {
        while (cmp(f[++l], target) < 0);
        while (cmp(f[--r], target) > 0);
        if (l < r) swap(f[l], f[r]);
    }
    swap(f[l], f[rb - 1]);
    quick_sort(lb, l - 1);
    quick_sort(l + 1, rb);
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) 
        cin >> f[i][0] >> f[i][1];
    // cout << f[1][0];
    quick_sort(0, n - 1);
    // for (int i = 0; i < n; i++)
    //     cout << '[' << f[i][0] << ',' << f[i][1] << ']' << ' ';
    // cout << f[m - 1][1] << ' ' << m << endl;
    string res;
    int index = 0, cnt = (int)(m * 1.5);
    int line = f[cnt][1];
    while ((index < cnt && f[index][1] >= f[cnt][1]) || (index < n && f[index][1] == f[index - 1][1])) {
        res += to_string(f[index][0]) + " " + to_string(f[index][1]) + "\n";
        line = f[index][1];
        index++;
    }
    cout << line << ' ' << index << endl;
    cout << res;
        // cout << '[' << f[i][0] << ',' << f[i][1] << ']' << ' ';
    return 0;
}
