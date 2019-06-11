#include <iostream>
using namespace std;

void dfs(string &str, int l, int r, string temp, int m) {
    if (m == 0 || l > r) {
        if (m == 0) {
            cout << temp << endl;
        }
        return;
    }
    dfs(str, l + 1, r, temp + str[l], m - 1);
    dfs(str, l + 1, r, temp, m);
}

int main() {
    string str = "abcd";
    
    int m = 3;
    string temp;
    for (int i = 1; i <= m; i++) {
        dfs(str, 0, str.size() - 1, temp, i);
    }
    return 0;
}