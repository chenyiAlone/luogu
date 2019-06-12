/*

题目背景
在双人对决的竞技性比赛，如乒乓球、羽毛球、国际象棋中，最常见的赛制是淘汰赛和循环赛。前者的特点是比赛场数少，每场都紧张刺激，但偶然性较高。后者的特点是较为公平，偶然性较低，但比赛过程往往十分冗长。

本题中介绍的瑞士轮赛制，因最早使用于18951895年在瑞士举办的国际象棋比赛而得名。它可以看作是淘汰赛与循环赛的折中，既保证了比赛的稳定性，又能使赛程不至于过长。

题目描述
2 \times N2×N 名编号为 1\sim 2N1∼2N 的选手共进行R 轮比赛。每轮比赛开始前，以及所有比赛结束后，都会按照总分从高到低对选手进行一次排名。选手的总分为第一轮开始前的初始分数加上已参加过的所有比赛的得分和。总分相同的，约定编号较小的选手排名靠前。

每轮比赛的对阵安排与该轮比赛开始前的排名有关：第11 名和第22 名、第 33 名和第 44名、……、第2K - 1 2K−1名和第 2K2K名、…… 、第2N - 1 2N−1名和第2N2N名，各进行一场比赛。每场比赛胜者得1 1分，负者得 0 0分。也就是说除了首轮以外，其它轮比赛的安排均不能事先确定，而是要取决于选手在之前比赛中的表现。

现给定每个选手的初始分数及其实力值，试计算在R 轮比赛过后，排名第 QQ 的选手编号是多少。我们假设选手的实力值两两不同，且每场比赛中实力值较高的总能获胜。

输入输出格式
输入格式：
第一行是三个正整数N,R ,QN,R,Q,每两个数之间用一个空格隔开，表示有 2 \times N 2×N名选手、RR 轮比赛，以及我们关心的名次 QQ。

第二行是2 \times N2×N 个非负整数s_1, s_2, …, s_{2N}s 
1
​	 ,s 
2
​	 ,…,s 
2N
​	 ，每两个数之间用一个空格隔开，其中 s_i s 
i
​	 表示编号为ii 的选手的初始分数。 第三行是2 \times N2×N 个正整数w_1 , w_2 , …, w_{2N}w 
1
​	 ,w 
2
​	 ,…,w 
2N
​	 ，每两个数之间用一个空格隔开，其中 w_iw 
i
​	  表示编号为ii 的选手的实力值。

输出格式：
一个整数，即RR 轮比赛结束后，排名第 QQ 的选手的编号。

输入输出样例
输入样例#1： 
2 4 2 
7 6 6 7 
10 5 20 15 
输出样例#1： 
1
说明
【样例解释】

思路:
    1. 归并排序，因为只有加一和减一的操作，将获胜的置于一个容器，失败的置于另一个容器，然后归并即可
    2. 这个题如果直接在每次比赛循环结束的时候使用快排，就会达到 O(r * n * n * log n) 的复杂度超时


*/
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct {
    int id;
    int sorce;
    int value;
} player;

bool cmp(const player &p1, const player &p2) {
    if (p1.sorce != p2.sorce) return p1.sorce > p2.sorce;
    return p1.id < p2.id;
}

int main() {
    int n, r, q;
    cin >> n >> r >> q;
    player players[n * 2] = {};
    memset(&players, 0, sizeof(players)); 
    for (int i = 0; i < n * 2; i++) {
        players[i].id = i + 1;
        cin >> players[i].sorce;
    }
    // cout << players[1].id;
    for (int i = 0; i < n * 2; i++) {
        cin >> players[i].value;
    }
    sort(players, players + (n * 2), cmp);
    // cout << "start: " << endl;
    // for (auto x : players)
    //         cout << "[" << x.id << ": " << x.sorce << "], ";
    // cout << endl;
    for (int i = 0; i < r; i++) {
        // player h1, h2, l1, l2;
        vector<player> win, lose;
        for (int j = 0; j < n * 2; j += 2) {
            if (players[j].value > players[j + 1].value) {
                players[j].sorce += 1;
                win.push_back(players[j]);
                lose.push_back(players[j + 1]);
                // f1.push_back(players[j]);
                // s2.push_back(players[j + 1]);
            } else {
                players[j + 1].sorce += 1;
                win.push_back(players[j + 1]);
                lose.push_back(players[j]);
                // f2.push_back(players[j]);
                // s1.push_back(players[j + 1]);
            }
        }
        for (int l = 0, r = 0, index = 0; l < win.size() || r < lose.size(); index++) {
            if (r == lose.size() || (l < win.size() && r < lose.size() && cmp(win[l], lose[r]))) {
                players[index] = win[l++];
            } else {
                players[index] = lose[r++];
            }
        }

        // cout << "f1 : ";
        // for (auto x : f1)
        //     cout << "[" << x.id << ": " << x.sorce << "], ";
        // cout << endl;
        // cout << "f2 : ";
        // for (auto x : f2)
        //     cout << "[" << x.id << ": " << x.sorce << "], ";
        // cout << endl;
        // cout << "s1 : ";
        // for (auto x : s1)
        //     cout << "[" << x.id << ": " << x.sorce << "], ";
        // cout << endl;
        // cout << "s2 : ";
        // for (auto x : s2)
        //     cout << "[" << x.id << ": " << x.sorce << "], ";
        // cout << endl;
        // for (auto x : players)
        //     cout << "[" << x.id << ": " << x.sorce << "], ";
        // cout << endl;
        // vector<player> temp1, temp2;
        // for (int l = 0, r = 0; l < f1.size() || r < f2.size(); ) {
        //     if (r == f2.size() || (l < f1.size() &&  r < f2.size() && cmp(f1[l], f2[r]))) {
        //         temp1.push_back(f1[l++]); 
        //     } else {
        //         temp1.push_back(f2[r++]);
        //     }
        // }
        // for (int l = 0, r = 0; l < s1.size() || r < s2.size(); ) {
        //     if (r == s2.size() || (l < s1.size() && r < s2.size() && cmp(s1[l], s2[r]))) {
        //         temp2.push_back(s1[l++]);
        //     } else {
        //         temp2.push_back(s2[r++]);
        //     }
        // }
        // cout << "temp1 : ";
        // for (auto x : temp1)
        //     cout << "[" << x.id << ": " << x.sorce << "], ";
        // cout << endl;
        // cout << "temp2 : ";
        // for (auto x : temp2)
        //     cout << "[" << x.id << ": " << x.sorce << "], ";
        // cout << endl;
        // for (int index = 0, l = 0, r = 0; l < temp1.size() || r < temp2.size(); index++) {
        //     if (r == temp2.size() || (l < temp1.size() && r < temp2.size() && cmp(temp1[l], temp2[r]))) {
        //         players[index] = temp1[l++];
        //     } else {
        //         players[index] = temp2[r++];
        //     }
        // }
        // for (auto x : players)
        //     cout << "[" << x.id << ": " << x.sorce << "], ";
        // cout << endl << endl;
    }
    // for (auto x : players)
    //     cout << "[" << x.id << ": " << x.sorce << "], ";
    cout << players[q - 1].id;
    return 0;
}