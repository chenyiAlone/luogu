#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
string nums_irr[] = { "a","both","another","first","second","third" };
string nums[20] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
                "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"};
int main() {
    string s;
    vector<int> values;
    for (int i = 0; i < 6; i++) {
        cin >> s;
        for (int j = 0; j < 6; j++) {
            if (nums_irr[j] == s) {
                values.push_back((j + 1) * (j + 1) % 100);
                // cout << "j: " << j << ", s: " << s << ", nums[i]: " << nums[i] << endl;
                break;
            }
        }
        for (int j = 0; j < 20; j++) {
            if (nums[j] == s) {
                values.push_back((j + 1) * (j + 1) % 100);
                // cout << "j: " << j << ", s: " << s << ", nums[i]: " << nums[i] << endl;
                break;
            }
        }
    }
    sort(values.begin(), values.end());
    int res = 0, i = 0, len = values.size();
    // for (auto x : values) {
    //     cout << x << ' ';
    // }
    // cout << endl;
    while (i < len && values[i] == 0) i++;
    while (i < len) {
        res = res * 100 + values[i];
        i++;
    }
    cout << res;
    return 0;
}
