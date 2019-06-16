#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
int n, cnt = 0, rows = 0, cols = 0;
vector<int> temp;

int fid(int x) {
    int ret = 0;
    while (x != 0) {
        x >>= 1;
        ret++;
    }
    return ret;
}

void ty(unsigned int a, unsigned int b, unsigned int c) {
    if (b == (1 << n) - 1) {
        cnt++;
        if (cnt <= 3) {
            for (int i = 0; i < temp.size(); i++)
                cout << temp[i] << ' ';
            cout << endl;
        }
        return;
    }
    unsigned int d = ~(a | b | c), board = ((~0 >> n) << n);
    while (d > board) {
        unsigned int bit = d & -d, ma = (((a | bit) << (32 - n)) << 1 ) >> (32 - n);
        temp.push_back(fid(bit));
        ty(ma, b | bit, (c | bit) >> 1);
        temp.pop_back();
        d -= bit;
    }
}

int main() {
    cin >> n;
    ty(0, 0, 0);
    cout << cnt;
    return 0;
}