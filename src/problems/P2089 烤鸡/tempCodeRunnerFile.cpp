#include <iostream>
using namespace std;
bool has_res = false;

void dfs(int n, string s, int cnt) {
    if (cnt <= 0 || n <= 0) {
        if (cnt == 0 && n == 0) {
            has_res = true;
            cout << s << endl;
        }
        return;
    }
    for (int i = 1; i <= 3; i++) {
        dfs(n - i, s + to_string(i) + ' ', cnt - 1);
    }
}

int main() {
    int n;
    cin >> n;
    dfs(n, "", 10);
    if (!has_res)
        cout << "0" << endl;
    return 0;
}