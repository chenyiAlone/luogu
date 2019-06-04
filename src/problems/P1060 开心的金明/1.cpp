/*

题目描述
金明今天很开心，家里购置的新房就要领钥匙了，新房里有一间他自己专用的很宽敞的房间。更让他高兴的是，妈妈昨天对他说：
“你的房间需要购买哪些物品，怎么布置，你说了算，只要不超过NN元钱就行”。今天一早金明就开始做预算，但是他想买的东西太多了，
肯定会超过妈妈限定的NN元。于是，他把每件物品规定了一个重要度，分为55等：用整数1-51−5表示，第55等最重要。
他还从因特网上查到了每件物品的价格（都是整数元）。他希望在不超过NN元（可以等于NN元）的前提下，
使每件物品的价格与重要度的乘积的总和最大。

设第j件物品的价格为1j]，重要度为uj]，共选中了k件物品，编号依次为1，j2，.，jk，则所求的总和为：
1j1]×wjjn]+vj2]×wj2]+.+v[jk]×wjk]。

请你帮助金明设计一个满足要求的购物单。

输入输出格式
输入格式：
第一行，为22个正整数，用一个空格隔开：N mNm（其中N(<30000)N(<30000)表示总钱数，m(<25)m(<25)为希望购买物品的个数。）

从第22行到第m+1m+1行，第jj行给出了编号为j-1j−1的物品的基本数据，每行有22个非负整数 v pvp（其中vv表示该物品的价格(v \le 10000)(v≤10000)，pp表示该物品的重要度(1-51−5)

输出格式：
11个正整数，为不超过总钱数的物品的价格与重要度乘积的总和的最大值(<100000000)(<100000000)。

输入输出样例
输入样例#1： 
1000 5
800 2
400 5
300 5
400 3
200 2
输出样例#1： 
3900

*/
#include <iostream>

using namespace std;

int main() {
    int m, n;
    cin >> n >> m;
    int v[m + 1], e[m + 1];
    
    for (int i = 1; i <= m; i++)
        cin >> v[i] >> e[i];
        
    int f[m + 1][n + 1];
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j] = f[i - 1][j];
            if (j > v[i]) {
                f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + v[i] * e[i]);
            }
        }
    }
    cout << f[m][n] << endl;
    return 0;
}