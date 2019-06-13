#include <iostream>
#include <string.h>
using namespace std;
int main() {
    string a("111");
    string b("111");
    string c("11");
    cout << "a.compare(b): " << a.compare(b) << endl;
    cout << "a == b: " << (a == b) << endl;
    cout << "a == c: " << (a == c) << endl;
    cout << "a.compare(c): " << a.compare(c) << endl;
    return 0;
}