/*


题目描述
所谓虫食算，就是原先的算式中有一部分被虫子啃掉了，需要我们根据剩下的数字来判定被啃掉的字母。来看一个简单的例子：

 43#9865#045
+  8468#6633
 44445509678
其中$#$号代表被虫子啃掉的数字。根据算式，我们很容易判断：第一行的两个数字分别是55和33，第二行的数字是55。

现在，我们对问题做两个限制：

首先，我们只考虑加法的虫食算。这里的加法是NN进制加法，算式中三个数都有NN位，允许有前导的00。

其次，虫子把所有的数都啃光了，我们只知道哪些数字是相同的，我们将相同的数字用相同的字母表示，不同的数字用不同的字母表示。如果这个算式是NN进制的，我们就取英文字母表午的前NN个大写字母来表示这个算式中的00到N-1N−1这NN个不同的数字：但是这NN个字母并不一定顺序地代表00到N-1N−1。输入数据保证NN个字母分别至少出现一次。

 BADC
+CBDA
 DCCC
上面的算式是一个4进制的算式。很显然，我们只要让ABCDABCD分别代表01230123，便可以让这个式子成立了。你的任务是，对于给定的NN进制加法算式，求出NN个不同的字母分别代表的数字，使得该加法算式成立。输入数据保证有且仅有一组解。

输入输出格式
输入格式：
包含四行。
第一行有一个正整数N(N \le 26)N(N≤26)。

后面的三行，每行有一个由大写字母组成的字符串，分别代表两个加数以及和。这3个字符串左右两端都没有空格，从高位到低位，并且恰好有NN位。

输出格式：
一行，即唯一的那组解。

解是这样表示的：输出NN个数字，分别表示A,B,C,…A,B,C,…所代表的数字，相邻的两个数字用一个空格隔开，不能有多余的空格。

输入输出样例
输入样例#1： 
5
ABCED
BDACE
EBBAA
输出样例#1： 
1 0 3 4 2


思路:
    从 n - 1 ~ 0 来推，过了，从 0 ~ n - 1 超时....


*/
#include <iostream>
#include <cstring>
using namespace std;
string a, b, c;
int n, nums[26], used[26], total[26], reord[26], re_id = 0, found = 0;

bool check() {
    int cy = 0;
    for (int i = n - 1; i >= 0; i--) {
        int sum = nums[a[i] - 'A'] + nums[b[i] - 'A'] + cy;
        if (sum % n != nums[c[i] - 'A']) return false;
        cy = sum / n;
    }
    return true;
}

bool can_prune() {
    if (nums[a[0] - 'A'] + nums[b[0] - 'A'] >= n) return true;
    for (int i = n - 1; i >= 0; i--) {
        int na = nums[a[i] - 'A'], nb = nums[b[i] - 'A'], nc = nums[c[i] - 'A'];
        bool flag = na != -1 && nb != -1 && nc != -1 && (na + nb) % n != nc && (na + nb + 1) % n != nc;
        if (flag) return true; 
    }
    return false;
}

void dfs(int cnt) {
    if (can_prune() || found) return;
    if (cnt == n) {
        if (check()) {
            found = 1;
            for (int i = 0; i < n; i++) {
                cout << nums[i] << ' ';
            }
        }
        return;
    }
    for (int j = n - 1; j >= 0; j--) {
        if (used[j] == 0) {
            used[j] = 1;
            nums[reord[cnt]] = j;

            dfs(cnt + 1);

            nums[reord[cnt]] = -1;
            used[j] = 0;
        }
    }
}

void add(int id) {
    if (used[id] == 0)
        reord[re_id++] = id;
    used[id] = 1;
}

int main() {
    cin >> n;
    memset(nums, -1, sizeof(nums));
    cin >> a >> b >> c;
    for (int i = n - 1; i >= 0; i--) {
        add(a[i] - 'A');  add(b[i] - 'A');  add(c[i] - 'A');
    }
    memset(used, 0, sizeof(used));
    // for (int i = 0; i < n; i++)
    //     cout << (char)(reord[i] + 'A') << ' ';
    // cout << endl;
    dfs(0);
    // int ans[] = {1, 0, 3, 4, 2};
    // memcpy(nums, ans, sizeof(ans));
    // cout << check();
    // cout << nums[2];

    return 0;
}