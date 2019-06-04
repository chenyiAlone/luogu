#include <iostream>
using namespace std;

int main() {
    int h1, h2, m1, m2;
    cin >> h1 >> m1 >> h2 >> m2;
    int h = h2 - h1;
    int m = 0;
    if (m2 < m1) {
        h -= 1;
        m2 += 60;
    }
    m = m2 - m1;
    cout << h << ' ' << m << endl;
    return 0;
}