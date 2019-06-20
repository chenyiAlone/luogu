/*

题目描述
高精度减法

输入输出格式
输入格式：
两个整数a,b（第二个可能比第一个大）

输出格式：
结果（是负数要输出负号）

输入输出样例
输入样例#1： 
2
1
输出样例#1： 
1
说明
20%数据a,b在long long范围内

100%数据0<a,b<=10的10000次方

思路:
    1. 迭代的顺序千万别反了

*/

#include <iostream>
#include <cstring>
using namespace std;
bool flag;
string s1, s2;

bool cmp(string &a, string &b) {
    int la = a.size(), lb = b.size();
    if (la != lb) return la < lb;
    for (int i = 0; i <= la - 1; i++) {
        if (a[i] != b[i]) {
            return a[i] < b[i];
        }
    }
    return false;
}

int main() {    
    cin >> s1 >> s2;
    if (cmp(s1, s2)) {  // a - b
        flag = true;
        swap(s1, s2);
    } 
    for (int i = 0, j = (int)s2.size() - s1.size(); i < s1.size(); i++, j++) {
        int a = s1[i] - '0', b = (j < 0 ? 0 : (s2[j] - '0'));
        if (a < b) {
            a += 10;
            int t = i - 1;
            while (s1[t] == '0') {
                s1[t] = '9';
                t--;
            }
            s1[t] -= 1;
        }
        int ans = a - b;
        s1[i] = '0' + ans;
    }
    int start = 0;
    while (s1[start] == '0' && start + 1 < s1.size()) start++;
    s1 = s1.substr(start);
    if (flag) s1 = '-' + s1;
    cout << s1 << endl;
    return 0;
}