#include <iostream>
using namespace std;

void dfs(string &str, int l, int r, string temp, int m) {
    if (m == 0 || l > r) {
        if (m == 0) {
            cout << temp << endl;
        }
        return;
    }
    for (int i = l; i <= r; i++) {
        dfs(str, i + 1, r, temp + str[i], m - 1);
    }
}

int main() {
    string str = "abcd";
    
    int m = 3;
    string temp;
    dfs(str, 0, str.size() - 1, temp, 3);
    return 0;
}