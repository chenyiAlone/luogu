#include <vector>
#include <iostream>
#include <numeric>

using namespace std;
int main() {

    vector<int> stk = {1, 2, 3};
    stk.pop_back();
    int sum = accumulate(stk.begin(), stk.end(), 0);
    
    cout << sum << endl;
    cout << stk.empty() << endl;
    cout << "a".compare("");
    return 0;
}