#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> cards(n, 0);
    int total = 0;
    for (int i = 0; i < n; i++) {
        cin >> cards[i];
        total += cards[i];
    }
    // 4
    //  9  8 17  6
    // 10  7 
    int ave = total / n;
    int last = 0;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int part = cards[i] - ave;
        if (cards[i] - ave > 0) {
            if (i + 1 < n) {
                cards[i + 1] -= part;
                res++;
            }
            // last += part;
        } else if (part == 0) {

        } else {
            if (i + 1 < n) {
                cards[i + 1] -= part;
                res++;
            }
        }
        last += part;
        cards[i] = ave;
    }
    // cout << total << ' ' << ave << ' ' << res << endl;
    cout << res;
    return 0;
}