/*

题目描述
小南有一套可爱的玩具小人, 它们各有不同的职业。

有一天, 这些玩具小人把小南的眼镜藏了起来。 小南发现玩具小人们围成了一个圈,它们有的面朝圈内,有的面朝圈外。如下图:



这时singersinger告诉小南一个谜題: “眼镜藏在我左数第3个玩具小人的右数第11个玩具小人的左数第22个玩具小人那里。 ”

小南发现, 这个谜题中玩具小人的朝向非常关键, 因为朝内和朝外的玩具小人的左右方向是相反的: 面朝圈内的玩具小人, 它的左边是顺时针方向, 右边是逆时针方向; 而面向圈外的玩具小人, 它的左边是逆时针方向, 右边是顺时针方向。

小南一边艰难地辨认着玩具小人, 一边数着:

singersinger朝内, 左数第33个是archerarcher。

archerarcher朝外,右数第11个是thinkerthinker。

thinkerthinker朝外, 左数第22个是writewriter。

所以眼镜藏在writerwriter这里!

虽然成功找回了眼镜, 但小南并没有放心。 如果下次有更多的玩具小人藏他的眼镜, 或是谜題的长度更长, 他可能就无法找到眼镜了 。 所以小南希望你写程序帮他解决类似的谜題。 这样的谜題具体可以描述为:

有 nn个玩具小人围成一圈, 已知它们的职业和朝向。现在第11个玩具小人告诉小南一个包含mm条指令的谜題, 其中第 zz条指令形如“左数/右数第 ss,个玩具小人”。 你需要输出依次数完这些指令后,到达的玩具小人的职业。

输入输出格式
输入格式：
输入的第一行包含两个正整数 n,mn,m，表示玩具小人的个数和指令的条数。

接下来 nn 行，每行包含一个整数和一个字符串，以逆时针为顺序给出每个玩具小人的朝向和职业。其中 00 表示朝向圈内，11 表示朝向圈外。 保证不会出现其他的数。字符串长度不超过 1010 且仅由小写字母构成，字符串不为空，并且字符串两两不同。整数和字符串之间用一个空格隔开。

接下来 mm 行，其中第 ii 行包含两个整数 a_i,s_ia 
i
​	 ,s 
i
​	 ，表示第 ii 条指令。若 a_i=0a 
i
​	 =0，表示向左数 s_is 
i
​	  个人；若 a_i=1a 
i
​	 =1，表示向右数 s_is 
i
​	  个人。 保证 a_ia 
i
​	  不会出现其他的数，1 \le s_i < n1≤s 
i
​	 <n。

输出格式：
输出一个字符串，表示从第一个读入的小人开始，依次数完 mm 条指令后到达的小人的职业。

输入输出样例
输入样例#1： 
7 3
0 singer
0 reader
0 mengbier 
1 thinker
1 archer
0 writer
1 mogician 
0 3
1 1
0 2
输出样例#1： 
writer
输入样例#2： 
10 10
1 C
0 r
0 P
1 d
1 e
1 m
1 t
1 y
1 u
0 V
1 7
1 1
1 4
0 5
0 3
0 1
1 6
1 2
0 8
0 4
输出样例#2： 
y
说明
【样例1说明】

这组数据就是【题目描述】 中提到的例子。

【子任务】

子任务会给出部分测试数据的特点。 如果你在解决题目中遇到了困难, 可以尝试只解决一部分测试数据。

每个测试点的数据规模及特点如下表:



其中一些简写的列意义如下:

• 全朝内: 若为“√”, 表示该测试点保证所有的玩具小人都朝向圈内;

全左数:若为“√”,表示该测试点保证所有的指令都向左数,即对任意的

1≤z≤m, a_i=01≤z≤m,a 
i
​	 =0;

s= 1s=1:若为“√”,表示该测试点保证所有的指令都只数1个,即对任意的

1≤z≤m,s_i=11≤z≤m,s 
i
​	 =1;

职业长度为11 :若为“√”,表示该测试点保证所有玩具小人的职业一定是一个

长度为11的字符串。

思路:

    1. 限定一个状态，使用数组来保存，0 代表朝内侧，1 代表外侧
    2. a = 0 向左，a = 1 向右，toy.first ^ a 
        状态:
            0 0 +
            0 1 -
            1 1 +
            1 0 -
    3. 实现左出界从右侧开始
        int mov = ((toys[index].first ^ a) ? b : -b) % n;
        index = (index + mov + (-mov > index ? n : 0)) % n;

*/
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;

    // 假设正面 0 为内，0 向左，1 向右
    vector< pair<bool, string> > toys(n, make_pair(false, "")); 
    for (int i = 0; i < n; i++) {
        cin >> toys[i].first >> toys[i].second;
    }
    // bool b = 1;
    // cout << toys[2].first << ' ' << toys[2].second;
    int index = 0;
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        // 0 0 +
        // 0 1 -
        // 1 1 +
        // 1 0 -
        int mov = ((toys[index].first ^ a) ? b : -b) % n;
        // int target = abs((index + mov) % n);
        // if (mov > 0) {
        //     index = (index + mov) % n;
        // } else {
        //     if (-mov > index) {
        //         index = n + index + mov;
        //     } else {
        //         index = index + mov;
        //     }
        // }
        // 条件判定化简
        index = (index + mov + (-mov > index ? n : 0)) % n;

        // cout << toys[index].first <<  ' ' << a <<  ' ' << (toys[index].first ^ a) << ' ' << mov << ' ' << index << ' ' << toys[index].second << endl;
    }
    cout << toys[index].second;
    // cout << -3 % 5 << endl;
    return 0;
}