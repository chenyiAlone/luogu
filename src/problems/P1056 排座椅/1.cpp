/*

题目描述
上课的时候总会有一些同学和前后左右的人交头接耳，这是令小学班主任十分头疼的一件事情。不过，班主任小雪发现了一些有趣的现象，当同学们的座次确定下来之后，只有有限的D对同学上课时会交头接耳。

同学们在教室中坐成了MM行NN列，坐在第i行第j列的同学的位置是(i,j)(i,j)，为了方便同学们进出，在教室中设置了KK条横向的通道，LL条纵向的通道。

于是，聪明的小雪想到了一个办法，或许可以减少上课时学生交头接耳的问题：她打算重新摆放桌椅，改变同学们桌椅间通道的位置，因为如果一条通道隔开了22个会交头接耳的同学，那么他们就不会交头接耳了。

请你帮忙给小雪编写一个程序，给出最好的通道划分方案。在该方案下，上课时交头接耳的学生的对数最少。

输入输出格式
输入格式：
第一行，有55个用空格隔开的整数，分别是M,N,K,L,D(2 \le N,M \le 1000,0 \le K<M,0 \le L<N,D \le 2000)M,N,K,L,D(2≤N,M≤1000,0≤K<M,0≤L<N,D≤2000)
接下来的DD行，每行有44个用空格隔开的整数。第ii行的44个整数X_i,Y_i,P_i,Q_iX 
i
​	 ,Y 
i
​	 ,P 
i
​	 ,Q 
i
​	 ，表示坐在位置(X_i,Y_i)(X 
i
​	 ,Y 
i
​	 )与(P_i,Q_i)(P 
i
​	 ,Q 
i
​	 )的两个同学会交头接耳（输入保证他们前后相邻或者左右相邻）。

输入数据保证最优方案的唯一性。

输出格式：
共两行。
第一行包含KK个整数a_1,a_2,…,a_Ka 
1
​	 ,a 
2
​	 ,…,a 
K
​	 ，表示第a_1a 
1
​	 行和a_1+1a 
1
​	 +1行之间、第a-2a−2行和a_2+1a 
2
​	 +1行之间、…、第a_Ka 
K
​	 行和第a_K+1a 
K
​	 +1行之间要开辟通道，其中a_i< a_i+1a 
i
​	 <a 
i
​	 +1，每两个整数之间用空格隔开（行尾没有空格）。

第二行包含LL个整数b_1,b_2,…,b_Lb 
1
​	 ,b 
2
​	 ,…,b 
L
​	 ，表示第b_1b 
1
​	 列和b_1+1b 
1
​	 +1列之间、第b_2b 
2
​	 列和b_2+1b 
2
​	 +1列之间、…、第b_Lb 
L
​	 列和第b_L+1b 
L
​	 +1列之间要开辟通道，其中b_i< b_i+1b 
i
​	 <b 
i
​	 +1，每两个整数之间用空格隔开（列尾没有空格）。

输入输出样例
输入样例#1： 
4 5 1 2 3
4 2 4 3
2 3 3 3
2 5 2 4
输出样例#1： 
2
2 4

思路:

    贪心
        优先选择存在交头接耳的对数最多的行、列添加到结果上，同时加入行、列号，这里处理起来有点混乱了，绕了挺久
    1. 将存在交头接耳的同学的对数，加到对应的行或者列上去 vector< pair<int, int> > p.first = row/low tag, p.second = count
    2. 按照 p.second 优先排列，然后将他们按照行、列号重新排列


*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
    if (p1.second == p2.second)
        return p1.first < p2.second;
    return p1.second > p2.second;
}


int main() {
    int m, n, k, l, d;
    cin >> m >> n >> k >> l >> d;
    vector< pair<int,int> > rows(m + 1, make_pair(0, 0));
    vector< pair<int,int> > cols(n + 1, make_pair(0, 0));

    for (int i = 0; i < d; i++) {
        int x, y, p, q;
        cin >> x >> y >> p >> q;
        if (x == p) { // 同一行
            int c = min(y, q);
            cols[c].first = c;
            cols[c].second += 1;
        } else {
            int r = min(x, p);
            rows[r].first = r;
            rows[r].second += 1;
        }
    }
    sort(rows.begin(), rows.end(), cmp);
    sort(cols.begin(), cols.end(), cmp);
    sort(rows.begin(), rows.begin() + k);
    sort(cols.begin(), cols.begin() + l);
    // for (int i = 0; i < rows.size(); i++) {
    //     cout << '[' << rows[i].first << ' ' << rows[i].second << "], ";
    // }
    // cout << endl;
    // for (int i = 0; i < cols.size(); i++) {
    //     cout << '[' << cols[i].first << ' ' << cols[i].second << "], ";
    // }
    // cout << endl;

    for (int i = 0; i < k; i++) {
        cout << rows[i].first << (i + 1 == k ? "" : " ");
    }
    cout << endl;
    for (int i = 0; i < l; i++) {
        cout << cols[i].first << (i + 1 == l ? "" : " ");
    }
    return 0;
}