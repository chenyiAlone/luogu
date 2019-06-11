#include <iostream>
#include <numeric>
#include <vector>
/*

1
8 O(n^2)
F x 1 n
F i 1 n
F k 1 n
E
E
F j 1 n
E
E

*/
using namespace std;
int main() {
int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int h;
        string o;
        cin >> h >> o;
        // cout << "h: " << h << ", h: "<< o << endl;
        int cnt = 0, w = 0, leve = 0;
        vector<int> vec;
        vector<char> vars;
        bool used[26] = {false}, error = false, constant = false;
        for (int j = 0; j < h; j++) {
            char type;
            cin >> type;
            // cout << "E: " << type << endl;
            if (type == 'E') {
                cnt--;
                w = max(w, accumulate(vec.begin(), vec.end(), 0));
                // cout << endl;
                cout << "v: ";
                for (auto x : vec)
                    cout << x << ", "; 
                cout << endl;
                if (!vec.empty()) {
                    vec.pop_back();
                    used[vars.back() - 'a'] = false;
                    vars.pop_back();
                }
                if (cnt < 0) {
                    error = true;
                    // break;
                }

            } else {
                cnt++;
                char v;
                string begin, end;
                // cout << "begin: " << begin << ", end: " << end << endl;
                cin >> v >> begin >> end;
                // cout << "v: " << v << ", begin: " << begin << ", end: " << end 
                //     << ", used[v]:" << used[v - 'a'] << endl;
                if (!used[v - 'a']) {
                    used[v - 'a'] = true;
                    vars.push_back(v);
                } else {
                    error = true;
                    // break;
                }
                // cout << (begin.compare("n") && end.compare("n")) << endl;
                if (end.compare("n") != 0 || (begin.compare("n") == 0 && end.compare("n") == 0)|| constant) {
                    if (begin.compare("n") == 0) {
                        constant = true;
                        // w = 0;
                    }
                    vec.push_back(0);
                    // cout << "no n!" << endl;
                } else {
                    // if (cnt != leve) {
                    //     w++;
                    //     leve = cnt;
                    // }
                    vec.push_back(1);

                }
            }
        }
        string res;
        // cout << i << " -> res: ";
        if (cnt != 0 || error) {
            // cout << "f: " << f << ", e: " << e << ", error: " << error << ' ';
            cout << "ERR" << endl;
            // res = "ERR";
        } else {
            if (w == 0) {
                res = "O(1)";
                // cout << "O(1)" << endl;
            } else  {
                // cout << "O(n^" << w << ")" << endl;
                res += "O(n^";
                res += to_string(w);
                res += ")";

            }
            cout << i + 1 << "-> res: " << res << endl;
            if (o.compare(res) == 0) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
        // cout << f << ' ' << e << ' ' << w << ' ' << endl;
        // cout << res.
    }
    return 0;
}

