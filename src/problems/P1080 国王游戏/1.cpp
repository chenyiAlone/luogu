/*

题目描述
恰逢 H H国国庆，国王邀请 nn 位大臣来玩一个有奖游戏。首先，他让每个大臣在左、右手上面分别写下一个整数，国王自己也在左、右手上各写一个整数。然后，让这 nn 位大臣排成一排，国王站在队伍的最前面。排好队后，所有的大臣都会获得国王奖赏的若干金币，每位大臣获得的金币数分别是：排在该大臣前面的所有人的左手上的数的乘积除以他自己右手上的数，然后向下取整得到的结果。

国王不希望某一个大臣获得特别多的奖赏，所以他想请你帮他重新安排一下队伍的顺序，使得获得奖赏最多的大臣，所获奖赏尽可能的少。注意，国王的位置始终在队伍的最前面。

输入输出格式
输入格式：
第一行包含一个整数 nn，表示大臣的人数。

第二行包含两个整数 aa和 bb，之间用一个空格隔开，分别表示国王左手和右手上的整数。

接下来 n n行，每行包含两个整数 aa 和 bb，之间用一个空格隔开，分别表示每个大臣左手和右手上的整数。

输出格式：
一个整数，表示重新排列后的队伍中获奖赏最多的大臣所获得的金币数。

输入输出样例
输入样例#1： 
3 
1 1 
2 3 
7 4 
4 6 
输出样例#1： 
2
说明
【输入输出样例说明】

按 11、22、33 这样排列队伍，获得奖赏最多的大臣所获得金币数为 22；

按 11、33、22 这样排列队伍，获得奖赏最多的大臣所获得金币数为 22；

按 22、11、33 这样排列队伍，获得奖赏最多的大臣所获得金币数为 22；

按 22、33、1 1这样排列队伍，获得奖赏最多的大臣所获得金币数为 99；

按 33、11、2 2这样排列队伍，获得奖赏最多的大臣所获得金币数为 22；

按 33、22、11 这样排列队伍，获得奖赏最多的大臣所获得金币数为 99。

因此，奖赏最多的大臣最少获得 2 2个金币，答案输出 22。

【数据范围】

对于 20%的数据，有 1≤ n≤ 10,0 < a,b < 81≤n≤10,0<a,b<8；

对于 40%的数据，有 1≤ n≤20,0 < a,b < 81≤n≤20,0<a,b<8；

对于 60%的数据，有 1≤ n≤1001≤n≤100；

对于 60%的数据，保证答案不超过 10^910 
9
 ；

对于 100%的数据，有 1 ≤ n ≤1,000,0 < a,b < 100001≤n≤1,000,0<a,b<10000。

NOIP 2012 提高组 第一天 第二题


思路:
    1. 贪心的选择 a * b 最小的排到前面
    2. 整数型不足以保存这么大的数，使用高精度进行计算


*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 1001
using namespace std;
int k[N*4], lk = 1, ans[N*4], la = 1, res[N*4], len = 1;

bool cmp(const pair<int, int> &p1, const pair<int, int> &p2) {
    return p1.first * p1.second < p2.first * p2.second;
}

void h_mul(int x) {
    for (int i = 1; i <= lk; i++) k[i] *= x;
    lk += 4;
    for (int i = 1; i <= lk; i++) {
        k[i + 1] += k[i] / 10;
        k[i] %= 10;
    }
    while (k[lk] == 0) lk--;
    // cout << "a: " << x <<  ", mul: ";
    // for (int j = lk; j > 0; j--)
    //     cout << k[j];
    // cout << endl;
}

void h_div(int x) {
    int w = 0, flag = 1;
    for (int i = lk; i > 0; i--) {
        w = w * 10 + k[i];
        ans[i] = w / x;
        w %= x;
        if (flag == 1 && ans[i] != 0) {
            flag = 0;
            la = i;
        }
    }
    // cout << "la: " << la << endl;
}

bool check() {
    if (la != len) return la > len;
    for (int i = la; i > 0; i--)
        if (ans[i] != res[i]) return ans[i] > res[i];
    return false;
}

int main() {
    memset(k, 0, sizeof(k));
	memset(ans, 0, sizeof(ans));
    memset(res, 0, sizeof(res));
    k[1] = 1;
    int n;
    cin >> n;
    vector< pair<int, int> > ministers(n + 1);
    for (int i = 0; i <= n; i++)
        cin >> ministers[i].first >> ministers[i].second;

    sort(ministers.begin() + 1, ministers.end(), cmp);

    // for (auto x : ministers)
    //     cout << "[" << x.first << ", " <<x.second << "], ";
    // cout << endl;
    h_mul(ministers[0].first);
    for (int i = 1; i <= n; i++) {
        
        h_div(ministers[i].second);
        if (check()) {
            memcpy(res, ans, sizeof(ans));
            len = la;
        }
        h_mul(ministers[i].first);
        
        
    }
    for (int i = len; i > 0; i--)
        cout << res[i];
    // cout << res;
    return 0;
}