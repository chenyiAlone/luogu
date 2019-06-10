#include <iostream>

using namespace std;


int main() {
    int p1, p2, p3;
    cin >> p1 >> p2 >> p3;
    bool fill = false;
    string str;
    cin >> str;
    string res;
    int k = p2, len = (int)str.size();
    for (int i = 0; i < len; i++) {
        if (0 < i && i + 1 < len && str[i] == '-' && str[i - 1] < str[i + 1]) {
            int begin = i - 1, end = i + 1;
            string temp;
            if (p3 == 2) swap(begin, end);
            // cout << begin << ' ' << end << endl;
            int step = (p3 == 2 ? -1 : 1);
            for (char j = str[begin] + step; j != str[end]; j += step) {
                for (int t = 0; t < k; t++) {
                    temp += (p1 == 1 ? j : (p1 == 2 ? (j - 32) : '*'));
                }
            }
            // cout << "temp: " << temp << endl;
            res += temp;
        } else {
            res += str[i];
        }
    }
    cout << res;
    return 0;
}