#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> v;
    v.push_back(1);
    cout << v.size() << endl;
    v.pop_back();
    cout << v.size() << endl;
    return 0;
}