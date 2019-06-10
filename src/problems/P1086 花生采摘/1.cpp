/*

题目描述
鲁宾逊先生有一只宠物猴，名叫多多。这天，他们两个正沿着乡间小路散步，突然发现路边的告示牌上贴着一张小小的纸条：“欢迎免费品尝我种的花生！――熊字”。

鲁宾逊先生和多多都很开心，因为花生正是他们的最爱。在告示牌背后，路边真的有一块花生田，花生植株整齐地排列成矩形网格（如图11）。有经验的多多一眼就能看出，每棵花生植株下的花生有多少。为了训练多多的算术，鲁宾逊先生说：“你先找出花生最多的植株，去采摘它的花生；然后再找出剩下的植株里花生最多的，去采摘它的花生；依此类推，不过你一定要在我限定的时间内回到路边。”



我们假定多多在每个单位时间内，可以做下列四件事情中的一件：

1) 从路边跳到最靠近路边（即第一行）的某棵花生植株；

2) 从一棵植株跳到前后左右与之相邻的另一棵植株；

3) 采摘一棵植株下的花生；

4) 从最靠近路边（即第一行）的某棵花生植株跳回路边。

现在给定一块花生田的大小和花生的分布，请问在限定时间内，多多最多可以采到多少个花生？注意可能只有部分植株下面长有花生，假设这些植株下的花生个数各不相同。

例如在图2所示的花生田里，只有位于(2, 5), (3, 7), (4, 2), (5, 4)(2,5),(3,7),(4,2),(5,4)的植株下长有花生，个数分别为13, 7, 15, 913,7,15,9。沿着图示的路线，多多在2121个单位时间内，最多可以采到3737个花生。

输入输出格式
输入格式：
第一行包括三个整数，M, NM,N和KK，用空格隔开；表示花生田的大小为M \times N(1 \le M, N \le 20)M×N(1≤M,N≤20)，多多采花生的限定时间为K(0 \le K \le 1000)K(0≤K≤1000)个单位时间。接下来的MM行，每行包括NN个非负整数，也用空格隔开；第i + 1i+1行的第jj个整数P_{ij}(0 \le P_{ij} \le 500)P 
ij
​	 (0≤P 
ij
​	 ≤500)表示花生田里植株(i, j)(i,j)下花生的数目，00表示该植株下没有花生。

输出格式：
一个整数，即在限定时间内，多多最多可以采到花生的个数。

输入输出样例
输入样例#1： 
6 7 21
0 0 0 0 0 0 0
0 0 0 0 13 0 0
0 0 0 0 0 0 7
0 15 0 0 0 0 0
0 0 0 9 0 0 0
0 0 0 0 0 0 0
输出样例#1： 
37
输入样例#2： 
6 7 20
0 0 0 0 0 0 0
0 0 0 0 13 0 0
0 0 0 0 0 0 7
0 15 0 0 0 0 0
0 0 0 9 0 0 0
0 0 0 0 0 0 0
输出样例#2： 
28

思路:

    1. 看清题目，每次必须采摘最大的数目的花生
    2. 转化为从当前位置到下一个位置能不能回到路边的问题
    3. 将储存了花生数目，坐标的数据类型按照花生数目的多少排序，只需要处理前面不为 0 即可统计出最大的结果


*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(const pair<int, pair<int, int> > &p1, const pair<int, pair<int, int> > &p2) {
    return p1.first > p2.first;
}

int main() {
    int m, n, k, res = 0;
    vector< pair<int, pair<int, int> > > field(21 * 21, make_pair(0, make_pair(0, 0)));
    cin >> m >> n >> k;
    int index = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            field[index].second = make_pair(i, j);
            cin >> field[index++].first;
        }
    }
    // cout << field[1].first << ' ' << field[1].second.first << ' ' << field[1].second.second << endl;
    sort(field.begin() + 1, field.begin() + index, cmp);
    for (int p = 1, sx = 0, sy = field[1].second.second; p < index && field[p].first > 0; p++) {
        int dx =  field[p].second.first, dy = field[p].second.second;
        int cost = abs(dx - sx) + abs(dy - sy) + 1;
        // cout << k << ' ' << cost << ' ' << res << ", next: " 
        //     << dx << ' ' << dy << ' ' << field[p].first << endl;
        if (k - cost - dx >= 0) {   // 可以到达下一个位置，更新起始左边
            res += field[p].first;
            sx = dx;    sy = dy;
            k -= cost;
        } else {
            break;
        }
    }
    cout << res;
    return 0;
}