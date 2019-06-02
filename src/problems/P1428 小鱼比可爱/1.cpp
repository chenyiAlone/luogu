#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int len;
vector<int> sum;


void add(int id, int val) {
    for (int i = id; i <= len; i += (i & -i)) {
        sum[i] += val;
    }
}

int get(int id) {
    int res = 0;
    for (int i = id; i > 0; i -= (i & -i)) {
        res += sum[i];
    }
    return res;
}

int main() {
    cin >> len;
    sum = vector<int>(len + 1, 0);
    vector<int> nums(len, 0);
    for (int i = 0, t; i < len; i++) {
        cin >> nums[i];
    }
    vector<int> v(nums);
    sort(v.begin(), v.end());
    int diff = v.end() - unique(v.begin(), v.end());

    for (int i = 0; i < diff; i++) {
        v.pop_back();
    }
    
    vector<int> dist(len, 0);
    for (int i = 0; i < len; i++) {
        dist[i] = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
    }
    vector<int> res(len, 0);
    for (int i = 0; i < len; i++) {
        res[i] = get(dist[i]);
        add(dist[i] + 1, 1);
    }
    for (auto x : res)
        cout << x << ' ';
    return 0;
}
