#include <iostream>
using namespace std;

void testString(string &s) {
    s[0] = 'a';


}

void testArray(int arr[]) {
    arr[0] = 1;

}

// int str_int(string &str) {
//     char res = 0;
//     char *p = &str;
//     sprintf(res, "%d", p);
//     return res;
// }

int main() {
    // string s = "b";
    // testString(s);
    // cout << s;
    // int n;
    // cin >> n;
    // int res = 0;
    // for (int i = 1, j = 1; i * i * i <= n && j * j <= n; i++) {
    //     while (i * i * i > j * j) j++;
    //     if (i * i * i == j * j && j * j <= n) {
    //         res++;
    //         j++;
    //     }
    // }
    // cout << res;
    // int arr[] = {2};
    // // testArray(arr);
    // cout << arr[0];
    string s("1");
    // cout << s.compare("a") <<endl;
    cout << atoi( s.c_str() );
    return 0;
}