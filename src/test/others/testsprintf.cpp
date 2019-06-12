#include <iostream>
#include <string.h>
using namespace std;

// void append(string s, ) {

// }

int main() {
    string a = "a";
    // char temp[1000];
    char *p = a.c_str();
    sprintf(p, "%s:%s", p, "test");
    a = string(p);
    cout << a;

    return 0;
}