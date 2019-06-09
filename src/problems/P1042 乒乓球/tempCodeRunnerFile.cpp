#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
    // string res11 = "", res21 = "";
    string str = "";
    char c;
    while ((c = getchar()) != 'E') {
        str += c;
    }
    cout << str;

    int own = 0, opp = 0;
    int len = str.size();
    for (int i = 0; i < len; i++) {
        own += str[i] == 'W';
        opp += str[i] == 'L';
         if ((own >= 11 && opp + 2 <= own)
            || (opp >= 11 && own + 2 <= opp) 
            || ( i + 1 == len)) {
            cout << own << ':' << opp << endl;
            own = 0;    opp = 0;
        }
    }
    cout << endl;
    for (int i = 0; i < len; i++) {
        own += str[i] == 'W';
        opp += str[i] == 'L';
         if ((own >= 21 && opp + 2 <= own)
            || (opp >= 21 && own + 2 <= opp) 
            || ( i + 1 == len)) {
            cout << own << ':' << opp << endl;
            own = 0;  opp = 0;
        }
    }
    return 0;
}
