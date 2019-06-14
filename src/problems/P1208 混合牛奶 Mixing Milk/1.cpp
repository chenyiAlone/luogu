/*

题目描述
由于乳制品产业利润很低，所以降低原材料（牛奶）价格就变得十分重要。帮助Marry乳业找到最优的牛奶采购方案。

Marry乳业从一些奶农手中采购牛奶，并且每一位奶农为乳制品加工企业提供的价格是不同的。此外，就像每头奶牛每天只能挤出固定数量的奶，每位奶农每天能提供的牛奶数量是一定的。每天Marry乳业可以从奶农手中采购到小于或者等于奶农最大产量的整数数量的牛奶。

给出Marry乳业每天对牛奶的需求量，还有每位奶农提供的牛奶单价和产量。计算采购足够数量的牛奶所需的最小花费。

注：每天所有奶农的总产量大于Marry乳业的需求量。

输入输出格式
输入格式：
第 1 行共二个数值:N,(0<=N<=2,000,000)是需要牛奶的总数；M,(0<= M<=5,000)是提供牛奶的农民个数。

第 2 到 M+1 行:每行二个整数:Pi 和 Ai。

Pi(0<= Pi<=1,000) 是农民 i 的牛奶的单价。

Ai(0 <= Ai <= 2,000,000)是农民 i 一天能卖给Marry的牛奶制造公司的牛奶数量。

输出格式：
单独的一行包含单独的一个整数，表示Marry的牛奶制造公司拿到所需的牛奶所要的最小费用。

输入输出样例
输入样例#1： 
100 5
5 20
9 40
3 10
8 80
6 30
输出样例#1： 
630
说明
题目翻译来自NOCOW。

USACO Training Section 1.3


思路:
    贪心选择最便宜的


*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector< pair<int, int> > farmers(m);
    for (int i = 0; i < m; i++)
        cin >> farmers[i].first >> farmers[i].second;
    sort(farmers.begin(), farmers.end());
    int res = 0, index = 0;
    while (n > 0) {
        res += farmers[index].first * (farmers[index].second < n ? farmers[index].second : n);
        n -= farmers[index].second;
        index++;
    }
    cout << res;
    return 0;
}