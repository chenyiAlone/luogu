#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int res = (1ll << 31) - 1, total;
    cin >> total;
    
    for (int i = 0; i < 3; i++) {
        int price, cnt;
        cin >> cnt >> price;
        int ans = price * (total / cnt + (total % cnt == 0 ? 0 : 1)); 
        res = min(res, ans);
    }
    cout << res;
    return 0;
}