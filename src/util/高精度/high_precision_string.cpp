#include <iostream>
using namespace std;

string add(string &n1, string &n2) {
    int i = n1.size() - 1, j = n2.size() - 1;
    // cout << i << ' ' << j << endl;
    int c = 0;
    string ret;
    while (i >= 0 || j >= 0) {
        int a = i >= 0 ? (n1[i] - '0') : 0, b = j >= 0 ? (n2[j] - '0') : 0;
        // cout << a << ' ' << b << endl;
        ret += ((a + b + c) % 10 + '0');
        c = (a + b + c) / 10;
        i--;    j--;
    }
    ret += (c == 0 ? "" : to_string(c));
    for (int l = 0, r = ret.size() - 1; l < r; l++, r--)
        swap(ret[l], ret[r]);
    // cout << "add solution: " << ret << endl;
    return ret;
}

string mul(string &n1, string &n2) {
    string ret;
    for (int i = n2.size() - 1; i >= 0; i--) {
        string sub_sum;
        int j = n1.size() - 1, c = 0;
        // cout << "n1.size(): " << n1.size() << endl;
        while (j >= 0) {
            int a = n1[j] - '0', b = n2[i] - '0';
            // cout << a << ' ' << b << endl;
            sub_sum += ((a * b + c) % 10 + '0');
            c = (a * b + c) / 10;
            j--;
        }
        sub_sum += (c == 0 ? "" : to_string(c));
        for (int l = 0, r = sub_sum.size() - 1; l < r; l++, r--)
            swap(sub_sum[l], sub_sum[r]);
        // cout << "sub_sum: " << sub_sum << ", ret: " << ret << endl;
        // cout << "add: " << add(ret, sub_sum) << endl;
        ret = add(ret, sub_sum);
        
    }
    return ret;
}

int main() {
    string n1 = "125";
    string n2 = "5";    
    cout << mul(n1, n2);

    return 0;
}