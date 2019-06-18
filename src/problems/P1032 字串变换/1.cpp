/*
题目描述
已知有两个字串A,BA,B及一组字串变换的规则（至多66个规则）:

A_1A 
1
​	  -> B_1B 
1
​	 
A_2A 
2
​	  -> B_2B 
2
​	 
规则的含义为：在 AA中的子串 A_1A 
1
​	  可以变换为 B_1B 
1
​	 ，A_2A 
2
​	  可以变换为 B_2B 
2
​	  …。

例如：AA='abcdabcd'BB＝'xyzxyz'

变换规则为：

‘abcabc’->‘xuxu’‘udud’->‘yy’‘yy’->‘yzyz’

则此时，AA可以经过一系列的变换变为BB，其变换的过程为：

‘abcdabcd’->‘xudxud’->‘xyxy’->‘xyzxyz’

共进行了33次变换，使得AA变换为BB。

输入输出格式
输入格式：
输入格式如下：

AA BB
A_1A 
1
​	  B_1B 
1
​	 
A_2A 
2
​	  B_2B 
2
​	  |-> 变换规则

... ... /

所有字符串长度的上限为2020。

输出格式：
输出至屏幕。格式如下：

若在1010步（包含1010步）以内能将AA变换为BB，则输出最少的变换步数；否则输出"NO ANSWER!"

输入输出样例
输入样例#1： 
abcd xyz
abc xu
ud y
y yz
输出样例#1： 
3

思路:
    1. BFS + struct + map
    2. 最麻烦的地方就是最后一题的超时了，刚开始只考虑到了出现一次的情况，
        忽视了在后面出现的情况，也是因为对 string 不是很熟悉的缘故，所以对于后面的匹配，
        忽然就慌了手脚，string :: int find(string s, int pos) 能够返回 pos 后的匹配位置 


*/
#include <iostream>
#include <map>
#include <queue>
using namespace std;

typedef struct {
    string str;
    int cnt;
} chain;

int n;
queue<chain> que;
map<string, int> ma;
string b_strs[6], e_strs[6], head, tail;


int main() {
    cin >> head >> tail;
    while (cin >> b_strs[n] >> e_strs[n]) n++;
    // for (int i = 0; i < 6; i++) {
    //     cin >> b_strs[i] >> e_strs[i];
    //     n = 6;
    // }
    que.push(chain {head, 0});
    for ( ; !que.empty(); que.pop()) {
        chain ch = que.front();
        // cout << ch.str << ' ' << ch.cnt;
        if (ch.cnt > 10) continue;
        if (ch.str == tail) {
            cout << ch.cnt << endl;
            return 0;
        }
        for (int i = 0; i < n; i++) {
            int p = ch.str.find(b_strs[i]);
            while (p != string :: npos) {
                string temp = ch.str.substr(0, p) + e_strs[i] + ch.str.substr(p + b_strs[i].size());
                // cout << p << endl;
                if (ma[temp] == 0 || ch.cnt + 1 < ma[temp]) {
                    que.push(chain {temp, ch.cnt + 1});
                    ma[temp] = ch.cnt + 1;
                }
                p = ch.str.find(b_strs[i], p + 1);
            }
        }
    }
    cout << "NO ANSWER!" << endl;
    return 0;
}