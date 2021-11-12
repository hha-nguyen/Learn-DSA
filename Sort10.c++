#include <iostream>
#include <stack>
#include <vector>
#define MAX_SIZE 100000
using namespace std;

int main() {
    int arr[MAX_SIZE][2], n;
    int arr1[MAX_SIZE][2];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i][0];
        cin >> arr[i][1];
    }
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n-i-1; ++j) {
            if (arr[j][0] > arr[j+1][0] || arr[j][0] == arr[j+1][0] && arr[j][1] > arr[j+1][0]) {
                int temp1 = arr[j][0];
                    arr[j][0] = arr[j+1][0];
                    arr[j+1][0] = temp1;
                int temp2 = arr[j][1];
                    arr[j][1] = arr[j+1][1];
                    arr[j+1][1] = temp2;
            }
        }
    }
    arr1[0][0] = arr[0][0];
    arr1[0][1] = arr[0][1];
    int index = 0;
    int min = arr[0][0], max = arr[0][1];
    for (int i = 1; i < n; ++i) {
        if (arr[i][0] <= max) {
            if (arr[i][1] > arr[i-1][1]) {
                max = arr[i][1];
                arr1[index][1] = max;
            } else continue;
        } else {
            index++;
            min = arr[i][0];
            max = arr[i][1];
            arr1[index][0] = min;
            arr1[index][1] = max;
        }
    }

    for (int i = 0; i < index+1; ++i) {
        cout << arr1[i][0] << " " << arr1[i][1] << endl;
    }

}