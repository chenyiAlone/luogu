/*

题目背景
宇宙总统竞选

题目描述
地球历公元6036年，全宇宙准备竞选一个最贤能的人当总统，共有n个非凡拔尖的人竞选总统，现在票数已经统计完毕，请你算出谁能够当上总统。

输入输出格式
输入格式：
president.in

第一行为一个整数n,代表竞选总统的人数。

接下来有n行，分别为第一个候选人到第n个候选人的票数。

输出格式：
president.out

共两行，第一行是一个整数m，为当上总统的人的号数。

第二行是当上总统的人的选票。

输入输出样例
输入样例#1： 
5
98765
12365
87954
1022356
985678
输出样例#1： 
4
1022356
说明
票数可能会很大，可能会到100位数字。

n<=20

思路:
    需要注意的地方就是更新的顺序，一定要先将 conds[ms] 置为 0，在将 ms = j
    

*/
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

string strs[20];
vector<int> conds(20, 0);
int main() {
    int n, maxLen = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
        maxLen = maxLen < strs[i].size() ? strs[i].size() : maxLen;
    }
    int m = 0;
    for (int i = 0; i < n; i++) {
        if (strs[i].size() == maxLen) {
            strs[m++] = strs[i];
            conds[i] = 1;
            // cout << i + 1;
        }
    }
    for (int i = 0; i < maxLen; i++) {
        int ms = 0;
        while (!conds[ms]) ms++;
        for (int j = ms + 1; j < m; j++) {
            if (conds[j] && strs[j][i] > strs[ms][i]) {
                conds[ms] = 0;
                ms = j;
            }
        }
        for (int j = 0; j < m; j++) {
            if (conds[j] && strs[j][i] < strs[ms][i]) {
                conds[j] = 0;
            }
        }
        int sum = accumulate(conds.begin(), conds.end(), 0);
        // cout << "sum: " << sum << endl;
        if (sum == 1) {
            cout << ms + 1 << endl << strs[ms];
            break;
        }

    }
    return 0;
}