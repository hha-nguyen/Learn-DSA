#include <iostream>
#include <string>
using namespace std;

int compareNum(long a, long b) {
    string aString = to_string(a);
    string bString = to_string(b);

    string sumStringAB = aString + bString;
    string sumStringBA = bString + aString;

    return (sumStringAB >= sumStringBA) ? 1 : -1;
}
void swap(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int arr[], int low, int high) {
    int position = low, partitonVale = arr[high];

    for (int j = low; j < high; j++) {
        if (compareNum(arr[j], arr[high]) > 0) {
            swap(&arr[j], &arr[position++]);
        }
    }
    swap(&arr[position], &arr[high]);
    return (position);
}

void quickSortMax(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSortMax(arr, low, p - 1);
        quickSortMax(arr, p + 1, high);
    }
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n + 1];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSortMax(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i];
    }
    cout << endl;

    return 0;
}