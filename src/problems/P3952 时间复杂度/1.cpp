#include <iostream>
#include <numeric>
#include <vector>
using namespace std;


int check(string &s1, string &s2) {
    // -1： 不执行， 0： 常数， 1： n
    // cout << "l: " << s1 << ", s2: " << s2 << endl;
    if (s1.compare("n") == 0) {
        if (s2.compare("n") == 0) {
            return 0;
        } else {
            return -1;
        }
    } else {    // s1=100
        if (s2.compare("n") == 0) {
            return 1;
        } else {
            // 常数
            int a = atoi( s1.c_str() );
            int b = atoi( s2.c_str() );
            // cout << 'a' << ' ' << a << ' ' << 'b' << ' ' << b << endl;
            if (a > b) {
                return -1;
            } else {
                return 0;
            }
        }
    }
}

int main() {
    // string l = "n", r = "n";
    // cout << check(l, r);
    
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int h, cnt = 0, unrun = -1, w = 0;
        string ans, type, l, r;
        char v;
        bool used[26] = {false}, error = false;
        vector<int> vars, degree;
        cin >> h >> ans;

        for (int j = 0; j < h; j++) {
            cin >> type;
            if (type.compare("F") == 0) {
                cnt++;

                cin >> v >> l >> r;
                if (used[v - 'a']) {
                    error = true;
                    // break;
                }
                used[v - 'a'] = true;
                vars.push_back(v - 'a');
                int flag = check(l, r);
                // cout << "flag: " << flag << endl;
                if (flag == -1) {
                    unrun = cnt;
                    // break;
                    degree.push_back(0);
                } else if (flag == 0 || unrun != -1) {
                    degree.push_back(0);
                } else {
                    degree.push_back(1);
                }
                // jump
                // string jump;
                // cin >> jump;
                //     if ()

            } else {    // type == E
                cnt--;
                if (unrun != -1 && unrun - 1 == cnt) {
                    unrun = -1;
                }
                w = max(w, accumulate(degree.begin(), degree.end(), 0));
                // cout << "v: ";
                // for (auto x : degree)
                //     cout << x << ", "; 
                // cout << endl;
                if (!degree.empty()) {
                    degree.pop_back();
                    used[vars.back()] = false; 
                    vars.pop_back();
                }
                if (cnt < 0) error = true;
            }
        }
        string res;
        // cout << "w: " << w << endl;
        if (error || cnt != 0) {
            // res = "ERR";
            cout << "ERR" << endl;
            continue;
        } else if (w == 0) {
            // cout << "O(1)" << endl;
            res = "O(1)";
        } else {
            // cout << "O(n^" << w << ")" << endl;
            res += "O(n^";
            res += to_string(w);
            res += ")";
        }
        if (res.compare(ans) == 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        // cout << i + 1 <<  "----------------------->" << res << endl;
    }
    return 0;
}