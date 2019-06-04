/*
题目描述
人比人，气死人；鱼比鱼，难死鱼。小鱼最近参加了一个“比可爱”比赛，比的是每只鱼的可爱程度。参赛的鱼被从左到右排成一排，头都朝向左边，然后每只鱼会得到一个整数数值，表示这只鱼的可爱程度，很显然整数越大，表示这只鱼越可爱，而且任意两只鱼的可爱程度可能一样。由于所有的鱼头都朝向左边，所以每只鱼只能看见在它左边的鱼的可爱程度，它们心里都在计算，在自己的眼力范围内有多少只鱼不如自己可爱呢。请你帮这些可爱但是鱼脑不够用的小鱼们计算一下。

输入输出格式
输入格式：
第一行输入一个整数n，表示鱼的数目。

第二行内输入n个整数，用空格间隔，依次表示从左到右每只小鱼的可爱程度。

输出格式：
行内输出n个整数，用空格间隔，依次表示每只小鱼眼中有多少只鱼不如自己可爱。

输入输出样例
输入样例#1： 
6
4 3 0 5 1 2
输出样例#1： 
0 0 0 3 1 2
说明
n<=100

思路：
    1. 重排序，去重，然后散列化重排序(按照题目要求，这里的比自己小的长度保存到 dist[i])
    2. 按照题目的方向(这里是向左看，即左边有多少个小于当前的数)
    3. 以 1 作为 val[即 个数 ] add(dist[i], 1))，并且得到 res[i] = get(dist[i]);

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int len;
vector<int> sum;

void add(int id, int val) {
    for (int i = id; i <= len; i += (i & -i)) {
        sum[i] += val;
    }
}

int get(int id) {
    int res = 0;
    for (int i = id; i > 0; i -= (i & -i)) {
        res += sum[i];
    }
    return res;
}

int main() {
    cin >> len;
    sum = vector<int>(len + 1, 0);
    vector<int> nums(len, 0);
    for (int i = 0, t; i < len; i++) {
        cin >> nums[i];
    }
    vector<int> v(nums);
    sort(v.begin(), v.end());
    int diff = v.end() - unique(v.begin(), v.end());

    for (int i = 0; i < diff; i++) {
        v.pop_back();
    }
    
    vector<int> dist(len, 0);
    for (int i = 0; i < len; i++) {
        dist[i] = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
    }
    vector<int> res(len, 0);
    for (int i = 0; i < len; i++) {
        res[i] = get(dist[i]);
        add(dist[i] + 1, 1);
    }
    for (auto x : res)
        cout << x << ' ';
    return 0;
}
