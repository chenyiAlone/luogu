/*
    P1421 小玉买文具
    
    题目描述
    班主任给小玉一个任务，到文具店里买尽量多的签字笔。已知一只签字笔的价格是1元9角，而班主任给小玉的钱是a元b角，小玉想知道，她最多能买多少只签字笔呢。

    输入输出格式
    输入格式：
    输入的数据，在一行内，包括两个整数，依次表示a和b，a<=10000,b<=9。

    输出格式：
    输出一个整数，表示小玉最多能买多少只签字笔。

    输入输出样例
    输入样例#1： 
    10 3
    输出样例#1： 
    5

*/
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int total;
    cin >> total;
    double res = 0;
    if (total < 151) {
        res = total * 0.4463;
    } else if (total < 401) {
        res = 150 * 0.4463 + (total - 150) * 0.4663;
    } else {
        res = 150 * 0.4463 + (400 - 150) * 0.4663 + (total - 400) * 0.5663;
    }
    
    printf("%0.1lf", res);
    
    return 0;
}
