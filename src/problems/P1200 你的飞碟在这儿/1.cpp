#include <iostream>
using namespace std;

int main() {
    string comet, group;
    cin >> comet >> group;
    int c_total = 1, g_total = 1;
    int len = max(group.size(), comet.size());
    for (int i = 0; i < len; i++) {
        if (i < group.size())
            g_total *= group[i] - 'A' + 1;
        if (i < comet.size())
            c_total *= comet[i] - 'A' + 1;
    }
    cout << (g_total % 47 == c_total % 47 ? "GO" : "STAY") << endl; 
    return 0;
}
