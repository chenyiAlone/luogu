/*
    题目描述
    已知 nn 个整数 x_1,x_2,…,x_nx 
    1
    ​	 ,x 
    2
    ​	 ,…,x 
    n
    ​	 ，以及11个整数kk(k<nk<n)。从nn个整数中任选kk个整数相加，可分别得到一系列的和。例如当n=4,k=3n=4,k=3,44个整数分别为3,7,12,193,7,12,19时，可得全部的组合与它们的和为：

    3+7+12=223+7+12=22

    3+7+19=293+7+19=29

    7+12+19=387+12+19=38

    3+12+19=343+12+19=34。

    现在，要求你计算出和为素数共有多少种。

    例如上例，只有一种的和为素数：3+7+19=293+7+19=29。

    输入输出格式
    输入格式：
    键盘输入，格式为：

    n,kn,k(1 \le n \le 20,k<n1≤n≤20,k<n)

    x_1,x_2,…,x_n (1 \le x_i \le 5000000)x 
    1
    ​	 ,x 
    2
    ​	 ,…,x 
    n
    ​	 (1≤x 
    i
    ​	 ≤5000000)
    输出格式：
    屏幕输出，格式为： 11个整数（满足条件的种数）。

    输入输出样例
    输入样例#1： 
    4 3
    3 7 12 19
    输出样例#1： 
    1

*/
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

bool isPrime(int n) {
    int s = (int)sqrt(n);
    for (int i = 2; i <= s; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int dfs(int index, int sum, int cnt, vector<int> nums) {
    if (cnt == 0) {
        // cout << sum << endl;
        return isPrime(sum);
    }
    int ret = 0;
    for (int i = index + 1; i < nums.size(); i++) {
        ret += dfs(i, sum + nums[i], cnt - 1, nums);
    }
    return ret;
}


int main() {
    int k, cnt;
    cin >> k >> cnt;
    vector<int> nums(k);
    for (int i = 0; i < k; i++) {
        cin >> nums[i];
    }
    int res = 0;
    for (int i = 0; i < k; i++) {
        res += dfs(i, nums[i], cnt - 1, nums);
    }


    cout << res;
    // cout << isPrime(1);

    // for (auto x : nums)
    //     cout << x << ' ';

    return 0;
}