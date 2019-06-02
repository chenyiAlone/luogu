#include <iostream>

using namespace std;

// int next[];

void getNext(string s, int next[]) {
    int len = s.size();
    next[0] = -1;
    int i = 0, j = -1;
    while (i < len) {
        if (j == -1 || s[i] == s[j]) {
            i++;
            j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}
/*
s :    a b a b a b a c
t :    a b a 
next: -1 0 0

*/
void kmp(string s, string t, int next[]) {
    int slen = s.size(), tlen = t.size();
    int i = 0, j = 0;
    while (i < slen) {
        // cout << i << ' ' << j << ' ' << endl;
        if (j == - 1 || s[i] == t[j]) {
            cout << i << ' ' << j << ' ' << endl;
            
            i++;
            j++;
        } else {
            j = next[j];
        }
        if (j == tlen) {
            cout << " index = " << i - tlen << endl;
            i--;
            j = 0;
        }
    }
    // if (j != tlen) {
    //         cout << ' j = ' << j;
    // }
}


int main() {
    string s, t;
    cin >> s >> t;
    int len = t.size();
    int next[len];
    getNext(t, next);
    // cout << next[0];
    kmp(s, t, next);

    cout << endl;
    for (int i = 0; i < len; i ++) {
        cout << next[i] << ' ';
    }

    return 0;
}