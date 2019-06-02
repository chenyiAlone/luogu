#include <iostream>
#include <string>
using namespace std;

void kmp(string&, string&);
void getNext(string&, int[]);

void kmp(string &s, string &t) {
    int slen = s.size(), tlen = t.size();
    int i = 0, j = 0;
    int next[tlen];
    getNext(t, next);

    int fId = 0, cnt = 0;
    while (i < slen && j < tlen) {
        if (j == -1 || s[i] == t[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
         if (j == tlen) {
            if (cnt == 0) {
                fId = i - tlen;
            }
            cnt++;
            j = 0;
            i -= (i == slen) ? 0 : 1;
        }
    }
    if (cnt == 0)
        cout << -1;
    else 
        cout << cnt << ' ' << fId;
   
}

void getNext(string &t, int next[]) {
    int i = 0, j = -1, len = t.size();
    next[0] = -1;
    while (i < len) {
        if (j == -1 || t[i] == t[j]) {
            i++;
            j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
    // for (int i = 0; i < len; i++)
    //     cout << next[i] << ' ';
    // cout << endl;
}

int main() {
    string s, t;
    // cin >> s >> t;
    // cout << t << s;
    getline(cin, t);
    getline(cin, s);
    s = " " + s + " ";
    t = " " + t + " ";
    int slen = s.size(), tlen = t.size();
    for (int i = 0; i < slen; i++)
        s[i] = tolower(s[i]);
    for (int i = 0; i < tlen; i++)
        t[i] = tolower(t[i]);
    // cout << t << endl << s;
    kmp(s, t);
    return 0;
}