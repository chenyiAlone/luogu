/*

题目背景
快noip了，yyy很紧张！

题目描述
现在各大oj上有n个比赛，每个比赛的开始、结束的时间点是知道的。

yyy认为，参加越多的比赛，noip就能考的越好（假的）

所以，他想知道他最多能参加几个比赛。

由于yyy是蒟蒻，如果要参加一个比赛必须善始善终，而且不能同时参加2个及以上的比赛。

输入输出格式
输入格式：
第一行是一个整数n ，接下来n行每行是2个整数ai,bi(ai<bi)，表示比赛开始、结束的时间。

输出格式：
一个整数最多参加的比赛数目。

输入输出样例
输入样例#1： 
3
0 2
2 4
1 3
输出样例#1： 
2
说明
对于20%的数据，n≤10；
对于50%的数据，n≤1000；
对于70%的数据，n≤100000；
对于100%的数据，n≤1000000，0≤ai＜bi≤1000000。


思路:
    1. 如果选择左端点进行排序，就可能出现开始很早，但是结束很晚的比赛，在这期间可能举行了多次比赛，就会跳过很多可以参加的比赛
    2. 所以这里使用右端点进行排序，那么这样他们的结束时间一定是按照非降序排列的，只需要判断当前比赛能不能在上一个比赛结束后参加即可

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector< pair<int, int> > exams(n);
    for (int i = 0; i < n; i++)
        cin >> exams[i].second >> exams[i].first;
    sort(exams.begin(), exams.end());
    int res = 0, end = -1;
    for (int i = 0; i < n; i++) {
        if (end <= exams[i].second) {
            res++;
            end = exams[i].first;
        }
    }
    cout << res;
    return 0;
}