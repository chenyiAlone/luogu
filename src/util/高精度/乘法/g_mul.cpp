#include <iostream>
#include <cstring>
#define N 4006
using namespace std;

int multiplicand[N] = {1}, end_index = 0, product[N];

void mul(string &num) {
    memset(product, 0, sizeof(product));
    int len = num.size();
    for (int i = len - 1; i >= 0; i--) {   // p 为
        int cy = 0, p = len - i - 1;
        // cout << "p: " << p << ", s[i]: " << s[i] << endl;
        for (int j = 0; j <= end_index + 1; j++) {
            int sum = product[p] + (num[i] - '0') * multiplicand[j] + cy;
            product[p++] = sum % 10;
            cy = sum / 10;
        }
        // if (cy != 0) product[p] = cy;
        // int cy2 = 0;
        // for (int j = 0; j <= end_index; j++) {
        //     int sum = multiplicand[j] + product[j] + cy2;
        //     multiplicand[j] = sum % 10;
        //     cy2 = sum / 10;
        // }
        // cout << "p: " << p << endl;
        // cout << "sub: ";
        // for (int j = 0; j <= end_index; j++)
        //     cout << product[j];
        // cout << endl;
        // cout << "multiplicand: ";
        // for (int j = 0; j <= end_index; j++)
        //     cout << multiplicand[j];
        // cout << endl;
    }
    // cout << "start end_index: " << end_index << endl;
    // memcpy(multiplicand, product, sizeof(product));
    end_index += len;
    while (end_index > 0 && product[end_index] == 0 ) end_index--;
    swap(multiplicand, product);
    // for (int i = 0; i <= end_index; i++)
    //     multiplicand[i] = product[i];
    // for (int i = 0; i <= end_index; i++)
    //     cout << multiplicand[i];
    // cout << endl;
    // cout << "final end_index: " << end_index << endl;
}

int main() {
    // while (1) {
        string a, b;
        cin >> a >> b;
        mul(a);
        // for (int i = a.size() - 1, j = 0; i >= 0; i--, j++) {
        //     multiplicand[j] = a[i] - '0';
        //     end_index += 1;
        // }
        mul(b);
        for (int i = end_index; i >= 0; i--)
            cout << multiplicand[i];
        cout << endl;
    // }
    return 0;
}