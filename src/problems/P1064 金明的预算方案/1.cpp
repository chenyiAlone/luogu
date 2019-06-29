/*

题目描述
金明今天很开心，家里购置的新房就要领钥匙了，新房里有一间金明自己专用的很宽敞的房间。更让他高兴的是，妈妈昨天对他说：“你的房间需要购买哪些物品，怎么布置，你说了算，只要不超过NN元钱就行”。今天一早，金明就开始做预算了，他把想买的物品分为两类：主件与附件，附件是从属于某个主件的，下表就是一些主件与附件的例子：

主件 附件

电脑 打印机，扫描仪

书柜 图书

书桌 台灯，文具

工作椅 无

如果要买归类为附件的物品，必须先买该附件所属的主件。每个主件可以有00个、11个或22个附件。附件不再有从属于自己的附件。金明想买的东西很多，肯定会超过妈妈限定的NN元。于是，他把每件物品规定了一个重要度，分为55等：用整数1-51−5表示，第55等最重要。他还从因特网上查到了每件物品的价格（都是1010元的整数倍）。他希望在不超过NN元（可以等于NN元）的前提下，使每件物品的价格与重要度的乘积的总和最大。

设第jj件物品的价格为v_[j]v 
[
​	 j]，重要度为w_[j]w 
[
​	 j]，共选中了kk件物品，编号依次为j_1,j_2,…,j_kj 
1
​	 ,j 
2
​	 ,…,j 
k
​	 ，则所求的总和为：

v_[j_1] \times w_[j_1]+v_[j_2] \times w_[j_2]+ …+v_[j_k] \times w_[j_k]v 
[
​	 j 
1
​	 ]×w 
[
​	 j 
1
​	 ]+v 
[
​	 j 
2
​	 ]×w 
[
​	 j 
2
​	 ]+…+v 
[
​	 j 
k
​	 ]×w 
[
​	 j 
k
​	 ]。

请你帮助金明设计一个满足要求的购物单。

输入输出格式
输入格式：
第11行，为两个正整数，用一个空格隔开：

N mNm （其中N(<32000)N(<32000)表示总钱数，m(<60)m(<60)为希望购买物品的个数。） 从第22行到第m+1m+1行，第jj行给出了编号为j-1j−1的物品的基本数据，每行有33个非负整数

v p qvpq （其中vv表示该物品的价格（v<10000v<10000），p表示该物品的重要度（1-51−5），qq表示该物品是主件还是附件。如果q=0q=0，表示该物品为主件，如果q>0q>0，表示该物品为附件，qq是所属主件的编号）

输出格式：
一个正整数，为不超过总钱数的物品的价格与重要度乘积的总和的最大值（<200000<200000）。

输入输出样例
输入样例#1： 
1000 5
800 2 0
400 5 1
300 5 1
400 3 0
500 2 0
输出样例#1： 
2200


思路:
    1. annex[main_id][annex_id][1] => annex_cost, annex[main_id][annex_id][2] => annex_value
    2. annex[main_id][0][0] 用来记录当前的主件有多少个附件
    3. 状态更新为
        1. 不选这个主件
        2. 选这个主件
            + 第一个附件
            + 第二个附件
            + 两个附件



*/


#include <iostream>
using namespace std;

int f[32001];
int annex[61][2][3];
int cost[61], value[61];
int n, m, v, p, q, cnt_main, cnt_annex;

int main() {
    cin >> n >> m;

    int cnt_main = 0;
    for (int i = 1; i <= m; i++) {
        cin >> v >> p >> q;
        if (q > 0) {
            int id = ++annex[q][0][0];  // 用来更新位置
            annex[q][id][1] = v;
            annex[q][id][2] = v * p;
        } else {
            // int id = ++cnt_main;
            cost[i] = v;
            value[i] = v * p;
        }
    }
    // for (int i = 0; i <= cnt_main; i++) {
    //     cout << cost[i] << ' ' << value[i] << endl;
    // }

    for (int i = 1; i <= m; i++) {
        for (int j = n; j >= cost[i]; j--) {
            f[j] = max(f[j], f[j - cost[i]] + value[i]);
            if (j >= cost[i] + annex[i][1][1]) {
                f[j] = max(f[j], f[j - cost[i] - annex[i][1][1]] + value[i] + annex[i][1][2]);
            }
            if (j >= cost[i] + annex[i][2][1]) {
                f[j] = max(f[j], f[j - cost[i] - annex[i][2][1]] + value[i] + annex[i][2][2]);
            }
            if (j >= cost[i] + annex[i][1][1] + annex[i][2][1]) {
                f[j] = max(f[j], f[j - cost[i] - annex[i][1][1] - annex[i][2][1]] + value[i] + annex[i][1][2] + annex[i][2][2]);
            }
        }
    }
    cout << f[n];
    // for (int i = 1; i <= m; i++) {
    //     cout << "{ [" << annex[i][1][1] << ", " << annex[i][1][2] << "], "
    //                     << annex[i][2][1] << ", " << annex[i][2][2] << "]} ";
    //     cout << endl;
    // }
    return 0;
}