#include <iostream>
#include <memory.h>
using namespace std;

int f[21][21][21];

int w(int a, int b, int c) {
    if (f[a][b][c] != -1)
        return f[a][b][c];
    if (a <= 0 || b <= 0 || c <= 0) 
        f[a][b][c] = 1;
    else if (a > 20 || b > 20 || c > 20)
        f[a][b][c] = w(20, 20, 20);
    else if (a < b && b < c)
        f[a][b][c] = w(a, b, c - 1)
                + w(a, b - 1, c - 1)
                - w(a, b - 1, c);
    else 
        f[a][b][c] = w(a - 1, b, c)
                    + w(a - 1, b - 1, c)
                    + w(a - 1, b, c - 1)
                    - w(a - 1, b - 1, c - 1);
    return f[a][b][c];
}


int main() {
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            memset(f[i][j], -1, sizeof(f[0][0]));
        }
    }

    int a, b, c;
    while (1) {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
            break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl;
    }
    return 0;
}