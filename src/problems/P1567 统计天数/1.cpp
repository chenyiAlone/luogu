#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int cnt = 0, res = 0, pre = -(1ll << 31);
    for (int i = 0, temp; i < n; i++) {
        cin >> temp;
        res = max(res, cnt);
        if (temp > pre) {
            cnt++;
        } else if (temp < pre)  {
            cnt = 1;
        }
        pre = temp;
    }
    cout << res;
    return 0;
}