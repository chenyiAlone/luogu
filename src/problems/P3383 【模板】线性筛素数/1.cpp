#include <iostream>
using namespace std;
int f[10000001] = {1, 1}, prime[10000001], n, m;
int main() {
    cin >> n >> m;
    for (int i = 2, pos = 0; i <= n; i++) {
        if (!f[i]) {
            prime[pos++] = i;
        }
        for (int j = 0; j < pos && i * prime[j] <= n; j++) {
            f[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    for (int i = 0, temp; i < m; i++) {
        cin >> temp;
        cout << (f[temp] == 0 ? "Yes" : "No") << endl;
    }
    // for (int i = 0; i <= n; i++)
    //     cout << prime[i] << ' ';
    // cout  << endl;

    return 0;
}