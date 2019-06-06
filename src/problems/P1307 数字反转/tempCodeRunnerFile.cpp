#include <iostream>
#include <stack>
using namespace std;

int main() {
    char c;
    stack<char> stk;
    bool neg = false;
    c = getchar();
    while (c != '\n') {
        if (c == '-')
            neg = true;
        else
            stk.push(c);
        c = getchar();
    }
    while (!stk.empty() && stk.top() == '0')
        stk.pop();
    if (neg)
        cout << '-';
    for ( ;!stk.empty(); stk.pop())
        cout << stk.top();
    return 0;
}