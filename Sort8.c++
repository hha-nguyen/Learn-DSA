#include <iostream>
#include <stack>
#include <vector>
#define MAX_SIZE 10000
using namespace std;
bool compareString (string a, string b) {
    int sum1 = 0, sum2 = 0;
    int len1 = a.length();
    int len2 = b.length();
    if (len1 != len2) return false;
    else {
        for (int i = 0; i < len1; ++i) {
            sum1 += a[i];
            sum2 += b[i];
        }
    }
    if (sum1 == sum2) return true;
    return false;
}
int main() {
    string arr[MAX_SIZE][2];
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i][0];
        cin >> arr[i][1];
    }
    for (int i = 0; i < n; ++i) {
        if (compareString(arr[i][0], arr[i][1]) == true) {
            cout << "yes" << endl;
        } else cout << "no" << endl;
    }
}