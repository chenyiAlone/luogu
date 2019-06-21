#include <iostream>
#include <cstring>
using namespace std;
string s1, s2;
int a[2001], b[2001], temp[4002], ans[4002]; 
int la, lb;

void mul() {
    int cy = 0;
    for (int i = 0; i < la + lb + 2; i++) {
        int sum = temp[i] + ans[i] + cy;
        ans[i] = sum % 10;
        cy = sum / 10;
    }
}

int main() {
    memset(ans, 0, sizeof(ans));
    cin >> s1 >> s2;
    la = s1.size(),lb = s2.size() ;
    for (int i = la - 1, j = 0; i >= 0; i--, j++)
        a[j] = s1[i] - '0';
    for (int i = lb - 1, j = 0; i >= 0; i--, j++)
        b[j] = s2[i] - '0';

    // for (int i = 0; i < la; i++)
    //     cout << a[i];    
    for (int i = 0; i < lb; i++) { // a * b
        memset(temp, 0, sizeof(temp));
        int cy = 0, j = 0, index = i;
        for (; j < la; j++) {
            int sum = a[j] * b[i] + cy;
            temp[index++] = sum % 10;
            cy = sum / 10;
        }
        if (cy != 0) temp[index] = cy;
        // cout << "temp: ";
        // for (int t = 0; t < la + lb + 1; t++)
        //     cout << temp[t] << ' ';
        // cout << endl;
        mul();
        // cout << "ans: ";
        // for (int t = 0; t < la + lb + 1; t++)
        //     cout << ans[t] << ' ';
    }
    // cout << "la: " << la << endl;
    // cout << "lb: " << lb << endl;
    // cout << "len: " << (la + lb + 1) << endl;
    // cout << la + lb + 1 << endl;
    // cout << ans[la + lb + 1] << endl;
    int len = la + lb + 1;
    while (ans[len] == 0 && len > 0) 
        len--;
    // for (int i = 0; i < la + lb; i++)
    //     cout << ans[i];
    // for (int i = 0; i)
    // cout << "len: " << len << endl;
    for (int i = len; i >= 0; i--)
        cout << ans[i];
    return 0;
}