/*

题目描述
检查一个如下的6 x 6的跳棋棋盘，有六个棋子被放置在棋盘上，使得每行、每列有且只有一个，每条对角线(包括两条主对角线的所有平行线)上至多有一个棋子。



上面的布局可以用序列2 4 6 1 3 5来描述，第i个数字表示在第i行的相应位置有一个棋子，如下：

行号 1 2 3 4 5 6

列号 2 4 6 1 3 5

这只是跳棋放置的一个解。请编一个程序找出所有跳棋放置的解。并把它们以上面的序列方法输出。解按字典顺序排列。请输出前3个解。最后一行是解的总个数。

//以下的话来自usaco官方，不代表洛谷观点

特别注意: 对于更大的N(棋盘大小N x N)你的程序应当改进得更有效。不要事先计算出所有解然后只输出(或是找到一个关于它的公式），这是作弊。如果你坚持作弊，那么你登陆USACO Training的帐号删除并且不能参加USACO的任何竞赛。我警告过你了！

输入输出格式
输入格式：
一个数字N (6 <= N <= 13) 表示棋盘是N x N大小的。

输出格式：
前三行为前三个解，每个解的两个数字之间用一个空格隔开。第四行只有一个数字，表示解的总数。

输入输出样例
输入样例#1： 
6
输出样例#1： 
2 4 6 1 3 5
3 6 2 5 1 4
4 1 5 2 6 3
4
说明
题目翻译来自NOCOW。

USACO Training Section 1.5

思路:
    1. dfs 当前行所有的所在行列对角线都不存在皇后的情况，将这一位填上 1 
    2. check(x, y) 判断三种情况
        f[i][j] == i &&
                j == y      |
            i + j == x + y  /
            i + y == x + j  \


*/
#include <iostream>
#include <vector>
using namespace std;

int f[13][13];
int n;
int cnt;
vector<int> temp;

bool check(int x, int y) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (f[i][j] == 1 && (i + j == x + y || x + j == i + y || j == y))   // 因为添加一个就会跳到下一行，所以不用进行行测
                return false;
        }
    }
    return true;
}

void dfs(int x) {
    // cout << x << ' ' << n << endl;
    if (x == n) {
        cnt++;
        // cout << "temp.size() :" << temp.size() << endl;
        if (cnt <= 3) {
            for (int i = 0; i < temp.size(); i++)
                cout << temp[i] << ' ';
            cout << endl;
        }
        return;
    }
    for (int y = 0; y < n; y++) {
        if (check(x, y)) {
            temp.push_back(y + 1);
            f[x][y] = 1;
            // cout << "dsf:" << x << ' ' << y << endl;
            dfs(x + 1);
            f[x][y] = 0;
            temp.pop_back();
        }
    }
}



int main() {
    cin >> n;
    dfs(0);
    cout << cnt;
    return 0;
}