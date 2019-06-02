#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> arr;
    int len;
    cin >> len;
    for (int i = 0, t = 0; i < len; i++) {
        cin >> t;
        arr.push_back(t);
    }
    sort(arr.begin(), arr.end());
    int res = 0;

    for (int i = len - 1; i > 0; i--) {
        // if (i > 0 && arr[i] == arr[i - 1])
        //     continue;
        for (int j = i - 1; j > 0; j--) {
            while (j > 0 && arr[j] == arr[j - 1]) {
                j--;
            }
            int t = arr[i] - arr[j];
            if (t < 1 || t == arr[j] )
                continue;
            bool found = false;
            for (int l = 0, r = j - 1; l <= r; ) {
                int mid = (l + r) >> 1;
                if (t < arr[mid]) {
                    r = mid - 1;
                } else if (arr[mid] < t) {
                    l = mid + 1;
                } else {
                    res ++;
                    found = true;
                    break;
                }
            }
            if (found)
                break;
        }
    }
    cout << res;
    return 0;
}

