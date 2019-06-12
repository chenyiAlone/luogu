#include <iostream>
using namespace std;
bool cmp(int a, int b) {
    return a < b;
}

int main() { 
    int a = 1, b = 2, c = 2;
    cout << "cmp(a, b): " << cmp(a, b) << endl;
    cout << "cmp(b, c): " << cmp(b, c) << endl;
    return 0;
}