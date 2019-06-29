#include <iostream>
using namespace std;

int f[2][2];

int main() {
    // f[1] = {1, 2};
    f[1][0] = 1;
    f[1][1] = 2;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << f[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}