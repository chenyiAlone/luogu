#include <iostream>
#include <math.h>

using namespace std;

int lboard, rboard;

bool isPrime(int n) {
    for (int i = 2; i <= (int)sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

void handle(int l, int r, int sum, int cnt, int len) {
    if (l < r || cnt <= 0) {
        if (cnt == 0 && isPrime(sum))
            cout << sum << endl; 
        return;
    }
    for (int j = (len == 1 ? 5 : 1); j <= 9; j += (r == 0 ? 2 : 1)) {
        int temp = 0;
        if (l == r) {
            temp = (int)pow(10, r) * j;
        } else {
            temp = (int)pow(10, l) * j + (int)pow(10, r) * j;
        }
        if (sum + temp < lboard || sum + temp > rboard)
            break;
        handle(l -1, r + 1, sum + temp, cnt - (l == r ? 1 : 2), len);
    }
}

int len(int n) {
    int ret = 0;
    while (n > 0) {
        ret++;
        n /= 10;
    }
    return ret;
}

void build() {
    int llen = len(lboard), rlen = len(rboard);
    
    for (int i = llen - 1; i < rlen; i++) {
        handle(i, 0, 0, i + 1, i + 1);
    }
    // cout << llen << ' ' << rlen << endl;

}

int main() {
    
    cin >> lboard >> rboard;
    build();
    return 0;
}