#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(const pair<int, int> &p1, const pair<int, int> &p2) {
    return p1.second < p2.second;
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector< pair<int, int> > ministers(n);
    for (int i = 0; i < n; i++)
        cin >> ministers[i].first >> ministers[i].second;
    sort(ministers.begin(), ministers.end(), cmp);
    // for (auto x : ministers)
    //     cout << "[" << x.first << ", " <<x.second << "], ";
    // cout << endl;
    long long total = a, res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, total / ministers[i].second);
        total *= ministers[i].first;
    }
    cout << res;
    return 0;
}