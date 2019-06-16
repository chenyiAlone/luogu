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

void dfs(int a, int b, int c) {
    if (b == (1 << n) - 1) {
        cnt++;
        if (cnt <= 3) {
            for (int i = 0; i < temp.size(); i++)
                cout << temp[i] << ' ';
            cout << endl;
        }
        return;
    }
    int d = (~(a | b | c) & (1 << n) - 1);
    while (d) {
        int bit = d & -d;
        temp.push_back(fid(bit));
        dfs((a | bit) << 1, b | bit, (c | bit) >> 1);
        temp.pop_back();
        d -= bit;
    }
}

int main() {
    cin >> n;
    dfs(0, 0, 0);
    cout << cnt;
    return 0;
}