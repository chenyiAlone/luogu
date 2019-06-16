/*

题目描述
单词接龙是一个与我们经常玩的成语接龙相类似的游戏，现在我们已知一组单词，且给定一个开头的字母，要求出以这个字母开头的最长的“龙”（每个单词都最多在“龙”中出现两次），在两个单词相连时，其重合部分合为一部分，例如 beastbeast和astonishastonish，如果接成一条龙则变为beastonishbeastonish，另外相邻的两部分不能存在包含关系，例如atat 和 atideatide 间不能相连。

输入输出格式
输入格式：
输入的第一行为一个单独的整数nn (n \le 20n≤20)表示单词数，以下nn 行每行有一个单词，输入的最后一行为一个单个字符，表示“龙”开头的字母。你可以假定以此字母开头的“龙”一定存在.

输出格式：
只需输出以此字母开头的最长的“龙”的长度

输入输出样例
输入样例#1： 
5
at
touch
cheat
choose
tact
a
输出样例#1： 
23
说明
（连成的“龙”为atoucheatactactouchoose）

思路:
    1. 接龙分为不可接龙和接最小的重复部分
    2. 处理开头。加进去一起算太繁琐了

*/
#include <iostream>
#include <vector>
using namespace std;

vector<string> words;
int n, res, used[20];

int connect(string &s1, string &s2) {
    int ret = 1;
    while (ret < s1.size() && ret < s2.size()) {
        int begin = s1.size() - ret;
        bool flag = true;
        for (int i = begin, j = 0; j < ret; i++, j++) {
            if (s1[i] != s2[j]) {
                flag = false;
                break;
            }
        }
        if (flag) return ret;
        ret++;
    }
    return -1;
}

void dfs(int index, int cur_len) {
    res = max(res, cur_len);
    for (int i = 0; i < n; i++) {
        int repeate = connect(words[index], words[i]);
        if (used[i] < 2 && (repeate != -1)) {
            used[i]++;
            dfs(i, cur_len + ((int)words[i].size()) - repeate);
            used[i]--;
        }
    }
}

int main() {
    cin >> n;
    words = vector<string>(n + 1);
    string temp;
    for (int i = 0; i < n ;i++) {
        cin >> words[i];
    }
    char begin;
    cin >> begin;
    for (int i = 0; i < n; i++) {
        if (words[i][0] == begin) {
            used[i]++;
            dfs(i, words[i].size());
            used[i]--;
        }
    }
    cout << res << endl;
    return 0;
}