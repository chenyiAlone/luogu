#include <iostream>
#include <stdio.h>
using namespace std;

long long coef, total;
int lor = 1;
char nkn;

int main() {
    string s = "";
    getline(cin, s);
    int i = 0, len = s.size();
    while (i < len) {
        // cout << i << ' ' << endl;
        int temp = -1, sign = 1;
        if (s[i] == '=') {
            lor = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        } else if (s[i] == '-') {
            sign = -1;
            i++;
        }
        if (i < len && '0' <= s[i] && s[i] <= '9') {
            temp = s[i++] - '0';
            while (i < len && '0' <= s[i] && s[i] <= '9') {
                temp = temp * 10 + (s[i] - '0');
                i++;
            }
        } 
        if (i < len && 'a' <= s[i] && s[i] <= 'z') {
            nkn = s[i];
            coef += sign * lor * (temp != -1 ? temp : 1);
            temp = 0;
            i++;
        }
        if (i < len && s[i] != '+' && s[i] != '-' && s[i] != '=')
            i++;
        total += (-lor) * ((temp == -1) ? 0 : temp) * sign;
    }
    // cout << coef << ' ' << total << endl;
    double res = (coef == 0) ? 0 : 1.0 * total / coef;
    cout << nkn << '=';
    printf("%.3lf", res);
    return 0;
}