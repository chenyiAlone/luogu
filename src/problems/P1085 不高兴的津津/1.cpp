#include <iostream>

using namespace std;

int main() {
    int i = 0;
    int time = 0, res = -1;
    while (i++ < 7) {
        int a, b;
        cin >> a >> b;
        if (a + b > 8 && a + b > time) {
            time = a + b;
            res = i;
        }
    }
    cout << res;
    return 0;
}