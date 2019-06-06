#include <iostream>

using namespace std;

int blanket[10001][5];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 4; j++)
            cin >> blanket[i][j];
    }
    int x, y;
    cin >> x >> y;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (blanket[i][1] <= x && x <= blanket[i][1] + blanket[i][3] 
            && blanket[i][2] <= y && y <= blanket[i][2] + blanket[i][4]) {
                res = i;
            }
    }
    if (res == 0)
        cout << -1 << endl;
    cout << res;
    return 0;
}