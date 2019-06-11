#include <iostream>
#include <vector>
using namespace std;
int f[100];
int n;

void sort(int lboard, int rboard) {
    if (lboard >= rboard)
        return;
    int mid = (lboard + rboard) >> 1;
    if (f[lboard] > f[mid]) swap(f[mid], f[lboard]);
    if (f[mid] > f[rboard]) swap(f[mid], f[rboard]);
    if (f[lboard] > f[mid]) swap(f[lboard], f[mid]);
    // cout << f[lboard] << ' ' << f[mid] << ' ' << f[rboard] << endl;
    swap(f[mid], f[rboard - 1]);
    int axis = f[rboard - 1];
    // cout << "axis: " << axis << endl; 
    int l = lboard, r = rboard - 1;
    while (l < r) {
        while (f[++l] < axis);
        while (f[--r] > axis);
        if (l < r) swap(f[l], f[r]);
    }
    swap(f[l], f[rboard -1]);
    // for (int i = 0; i < n; i++) 
    //     cout << f[i] << ' ';
    //     cout << endl;
    // cout << l << endl;
    sort(lboard, l - 1);
    sort(l + 1, rboard);
}


int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> f[i];
    sort(0, n - 1);
    int len = 0;
    vector<int> res;
    for (int i = 0; i < n; i++) {
        if (len == 0 || f[i] != res[len - 1]) {
            res.push_back(f[i]);
            len++;
        }
    }
    cout << len << endl;
    for (int i = 0; i < len; i++)
        cout << res[i] << ' ';
    return 0;
}