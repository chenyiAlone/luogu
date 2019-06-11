#include <iostream>
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
        bool used[26] = {false}, error = false, constant = false;
        for (int j = 0; j < h; j++) {
            char type;
            cin >> type;
            // cout << "E: " << type << endl;
            if (type == 'E') {
                cnt--;
                if (cnt < 0) break;
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
                } else {
                    error = true;
                }
                // cout << (begin.compare("n") && end.compare("n")) << endl;
                if (end.compare("n") != 0 || constant) {
                    if (begin.compare("n") == 0) {
                        constant = true;
                        w = 0;
                    }
                    // cout << "no n!" << endl;
                } else {
                    if (cnt != leve) {
                        w++;
                        leve = cnt;
                    }
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