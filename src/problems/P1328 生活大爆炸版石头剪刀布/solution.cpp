#include <iostream>
using namespace std;

int fa[200], fb[200];
int vs[5][5] = {{0, 0, 1, 1, 0}, 
                {1, 0, 0, 1, 0}, 
                {0, 1, 0, 0, 1},
                {0, 0, 1, 0, 1}, 
                {1, 1, 0, 0, 0}};
int main() {
    int n, a, b;
    cin >> n >> a >> b;
    
    for (int i = 0; i < a; i++) {
        cin >> fa[i];
    }
    for (int i = 0; i < b; i++) {
        cin >> fb[i];
    }
    int wa = 0, wb = 0;
    for (int i = 0; i < n; i++) {
        wa += vs[fa[i % a]][fb[i % b]];
        wb += vs[fb[i % b]][fa[i % a]];
    }
    cout << wa << ' ' << wb;
    return 0;
}