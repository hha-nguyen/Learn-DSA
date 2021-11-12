#include <iostream>
#include <stack>
#include <vector>
#define MAX_SIZE 10000
using namespace std;
bool compareString (string a, string b) {
    if (a.length() < b.length()) return true;
    if (a.length() == b.length() && a < b) return true;
    return false;
}
int main() {
    string arr[MAX_SIZE];
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n-i-1; ++j) {
            if (compareString(arr[j], arr[j+1]) == false) {
                string  temp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = temp;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << endl;
    }
}