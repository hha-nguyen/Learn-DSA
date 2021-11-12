#include <iostream>
using namespace std;

int main() {
    int n, k, arr[100000], sum = 0;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (abs(arr[i] - arr[j]) == 2) {
                sum++;
            }
        }
    }
    cout << sum;
}