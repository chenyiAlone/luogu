#include <iostream>
#include <string>
using namespace std;

int main() {
    int cnt[26] = {0};
    // cout << cnt[20];
    string s;
    int maxCnt = 0;
    for (int i = 0; i < 4; i++) {
        getline(cin, s);
        for (int j = 0; j < s.size(); j++) {
            int c = s[j] - 'A';
            if (0 <= c && c <= 26) {
                cnt[c] += 1;
                maxCnt = max(maxCnt, cnt[c]);
            }
        }
    }
    while (maxCnt > 0) {
        int end = 0;
        for (int i = 0; i < 26; i++)
            if (cnt[i] == maxCnt)
                end = i;
        for (int i = 0; i <= end; i++) {

            if (cnt[i] == maxCnt) {
                cnt[i]--;
                cout << '*';
            } else {
                cout << ' ';
            }
            if (i != end)
                cout << ' ';
                
        }
        cout << endl;
        maxCnt--;
    }
    cout << 'A';
    for (char c = 'B'; c <= 'Z'; c++)
        cout << ' ' << c;
    return 0;
}