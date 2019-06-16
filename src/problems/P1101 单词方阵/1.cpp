/*

题目描述
给一n \times nn×n的字母方阵，内可能蕴含多个“yizhong”单词。单词在方阵中是沿着同一方向连续摆放的。摆放可沿着 88 个方向的任一方向，同一单词摆放时不再改变方向，单词与单词之间可以交叉,因此有可能共用字母。输出时，将不是单词的字母用*代替，以突出显示单词。例如：

输入：
    8                     输出：
    qyizhong              *yizhong
    gydthkjy              gy******
    nwidghji              n*i*****
    orbzsfgz              o**z****
    hhgrhwth              h***h***
    zzzzzozo              z****o**
    iwdfrgng              i*****n*
    yyyygggg              y******g
输入输出格式
输入格式：
第一行输入一个数nn。(7 \le n \le 1007≤n≤100)。

第二行开始输入n \times nn×n的字母矩阵。

输出格式：
突出显示单词的n \times nn×n矩阵。

输入输出样例
输入样例#1： 
7
aaaaaaa
aaaaaaa
aaaaaaa
aaaaaaa
aaaaaaa
aaaaaaa
aaaaaaa
输出样例#1： 
*******
*******
*******
*******
*******
*******
*******
输入样例#2： 
8
qyizhong
gydthkjy
nwidghji
orbzsfgz
hhgrhwth
zzzzzozo
iwdfrgng
yyyygggg
输出样例#2： 
*yizhong
gy******
n*i*****
o**z****
h***h***
z****o**
i*****n*
y******g


思路:
    1. 因为退出的边界问题，应该是 index == "yizhong".size() - 1
    2. 沿一条直线摆放，在开始的时候指定 8 个方式即可

*/
#include <iostream>
#include <vector>

using namespace std;
int n, m = 7;
string s = "yizhong";
vector<string> strs;
bool f[100][100], trace[100][100];

int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

bool dfs(int x, int y, int i, int index) {
    trace[x][y] = true;
    bool flag = false;
    if (index == m - 1) {
        // cout << "yes" << endl;
        flag = true;
    } else {
        int nx = x + dx[i], ny = y + dy[i];
        if (0 <= nx && nx < n && 0 <= ny && ny < n && s[index + 1] == strs[nx][ny] && !trace[nx][ny]) {
            flag = dfs(nx, ny, i, index + 1);
        }
    }
    if (flag) {
        f[x][y] = true;
    }
    trace[x][y] = false;
    return flag;
}

int main() {
    cin >> n;
    strs = vector<string>(n);
    for (int i = 0; i < n; i++)
        cin >> strs[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (strs[i][j] == s[0]) {
                for (int t = 0; t < 8; t++)
                    dfs(i, j, t, 0);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (f[i][j] ? strs[i][j] : '*');
        }
        cout << endl;
    }
    return 0;
}