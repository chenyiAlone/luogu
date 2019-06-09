/*

题目描述
有NN堆纸牌，编号分别为 1,2,…,N1,2,…,N。每堆上有若干张，但纸牌总数必为NN的倍数。可以在任一堆上取若干张纸牌，然后移动。

移牌规则为：在编号为11堆上取的纸牌，只能移到编号为22的堆上；在编号为NN的堆上取的纸牌，只能移到编号为N-1N−1的堆上；其他堆上取的纸牌，可以移到相邻左边或右边的堆上。

现在要求找出一种移动方法，用最少的移动次数使每堆上纸牌数都一样多。

例如N=4N=4，44堆纸牌数分别为：

①99②88③1717④66
移动33次可达到目的：

从 ③ 取44张牌放到 ④ （9,8,13,109,8,13,10）-> 从 ③ 取33张牌放到 ②（9,11,10,109,11,10,10）-> 从 ② 取11张牌放到①（10,10,10,1010,10,10,10）。

输入输出格式
输入格式：
两行

第一行为：NN（NN 堆纸牌，1 \le N \le 1001≤N≤100）

第二行为：A_1,A_2, … ,A_nA 
1
​	 ,A 
2
​	 ,…,A 
n
​	  （NN堆纸牌，每堆纸牌初始数，1 \le A_i \le 100001≤A 
i
​	 ≤10000）

输出格式：
一行：即所有堆均达到相等时的最少移动次数。

输入输出样例
输入样例#1： 
4
9 8 17 6
输出样例#1： 
3

思路:

    1. 求出当前的元素相对于 ave 分摊后的值的差 part
    2. part != 0 && i + 1 != n，res++，cards[i + 1] += part;


*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> cards(n, 0);
    int total = 0;
    for (int i = 0; i < n; i++) {
        cin >> cards[i];
        total += cards[i];
    }
    int res = 0, ave = total / n;
    for (int i = 0; i < n; i++) {
        int part = cards[i] - ave;
        if (part != 0 && i + 1 < n) {
            cards[i + 1] += part;
            res++;
        }
    }
    // cout << total << ' ' << ave << ' ' << res << endl;
    cout << res;
    return 0;
}