/*

题目描述
某校大门外长度为L的马路上有一排树，每两棵相邻的树之间的间隔都是11米。我们可以把马路看成一个数轴，马路的一端在数轴00的位置，另一端在LL的位置；数轴上的每个整数点，即0,1,2,…,L0,1,2,…,L，都种有一棵树。

由于马路上有一些区域要用来建地铁。这些区域用它们在数轴上的起始点和终止点表示。已知任一区域的起始点和终止点的坐标都是整数，区域之间可能有重合的部分。现在要把这些区域中的树（包括区域端点处的两棵树）移走。你的任务是计算将这些树都移走后，马路上还有多少棵树。

输入输出格式
输入格式：
第一行有22个整数L(1 \le L \le 10000)L(1≤L≤10000)和 M(1 \le M \le 100)M(1≤M≤100)，LL代表马路的长度，MM代表区域的数目，LL和MM之间用一个空格隔开。
接下来的MM行每行包含22个不同的整数，用一个空格隔开，表示一个区域的起始点和终止点的坐标。

输出格式：
11个整数，表示马路上剩余的树的数目。

输入输出样例
输入样例#1： 
500 3
150 300
100 200
470 471
输出样例#1： 
298

思路：
    1. 并集合并问题，begins, ends, entires -> sort()
    2. lboard 记录第一个其实的左端点，cnt 计数，左端点 +1，右端点 -1，cnt == 0，res.push_back(lboard, nums[i]);
    3. res = len + 1 - 所有的 (区间长度 + 1)


*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v;
    vector<int> begin;
    vector<int> end;
    vector< pair<int, int> > res;
    int len, k;
    cin >> len >> k;
    for (int i = 0; i < k; i++){
        int tb, te;
        cin >> tb >> te;
        begin.push_back(tb);
        end.push_back(te);
        v.push_back(tb);
        v.push_back(te);
    }

    sort(v.begin(), v.end());
    sort(begin.begin(), begin.end());
    sort(end.begin(), end.end());

    int size = v.size();
    int total = len + 1;

    for (int i = 0, cnt = 0, lboard = 0, bIndex = 0, eIndex = 0; i < size; i++) {
        while (bIndex < size && v[i] == begin[bIndex]) {
            cnt++;
            bIndex++;
            if (cnt == 1) {
                lboard = v[i];
            }
        }
        while (eIndex < size && v[i] == end[eIndex]) {
            cnt--;
            eIndex++;
            if (cnt == 0) {
                total -= (v[i] - lboard + 1);
            }
        }
    }
    cout << total;
    return 0;
}