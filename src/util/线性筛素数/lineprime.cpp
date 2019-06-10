#include <iostream>
#define SIZE 1000

using namespace std;

int main() {
    bool iscom[SIZE] = {false};  
    int prime[SIZE] = {0};
    int pos=0;
    int flag;
    for (int i = 2 ; i < SIZE ; i++) {
        if (!iscom[i])  // 不是合数，也就是质素，添加到 prime[] 中
            prime[pos++] = i;

        for (int j = 0 ; j < pos && i * prime[j] < SIZE ; j++) {
            iscom[i * prime[j]] = 1;  // 筛掉 *已经筛选* 出来的质数和 i 的乘积小于 size 的所有合数
            if (i % prime[j] == 0)
                break;
        }
    }

    for (int i = 0; i < 100; i++)
        cout << prime[i] << ' ';

    return 0;
}