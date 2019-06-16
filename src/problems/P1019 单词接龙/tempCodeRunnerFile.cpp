#include <iostream>
#include <vector>
using namespace std;

int n, res;
int used[20];
vector<string> words;
vector<string> temp;
int connect(string &s1, string &s2) {
    int ret = -1, cl = 1;
    while (cl < s1.size() && cl < s2.size()) {
        int begin = s1.size() - cl;
        bool flag = true;
        for (int i = begin, j = 0; j < cl; i++, j++) {
            if (s1[i] != s2[j]) {
                flag = false;
                break;
            }
        }
        if (flag) ret = max(ret, cl);
        cl++;
    }
    return ret;
}

void dfs(int index, int cur_len) {
    res = max(res, cur_len);
    for (int i = 0; i < n; i++) {
        int repeate = connect(words[index], words[i]);
        if (used[i] < 2 && (repeate != -1)) {
            used[i]++;
            temp.push_back(words[i]);
            dfs(i, cur_len + ((int)words[i].size()) - repeate);
            temp.pop_back();
            used[i]--;
        }
    }
}


int main() {
    cin >> n;
    words = vector<string>(n + 1);
    string temp;
    for (int i = 0; i < n ;i++) {
        cin >> words[i];

    }
    char begin;
    cin >> begin;
    for (int i = 0; i < n; i++) {
        if (words[i][0] == begin) {
            used[i]++;
            dfs(i, words[i].size());
            used[i]--;
        }
    }
    // words[n] = " " + words[n];
    cout << res;
    // string s1 = "touch";
    // string s2 = "choose";
    // cout << connect(s1, s2);
    return 0;
}