#include <iostream>
using namespace std;

void testString(string &s) {
    s[0] = 'a';


}

void testArray(int arr[]) {
    arr[0] = 1;

}


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
    int arr[] = {2};
    testArray(arr);
    cout << arr[0];
    return 0;
}