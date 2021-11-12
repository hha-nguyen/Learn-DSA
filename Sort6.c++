#include <iostream>
#include <vector>
using namespace std;

int Check(vector<int> vec, int n) {
    int size = vec.size();
    if (size == 1) return 1;
    for (int i = 0; i < size; ++i) {
        if (n < vec[i]) return 1;
    }
    return 0;
}
int main() {
    int n, k;
    cin >> n >> k;
    int arr[n+1];
    vector<int> vec;
    int a, b, count = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (arr[i] + arr[j] == k) {
                count++;
                int checkNum = i*n +j;
                vec.push_back(checkNum);
                if (Check(vec, checkNum)) {
                    a = i+1, b = j+1;
                }
            }
        }
    }
    if (count != 0) 
        cout << a << " " << b;
    else cout << -1;
}