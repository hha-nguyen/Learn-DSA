#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
        a = b;
        b = temp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int left = low;
    int right = high-1;
    while (true) {
        while (left <= right && arr[left] < pivot) left++; //find >= pivot
        while (left <= right && arr[right] > pivot) right--; //find <= pivot
        if (left >= right) break; //out of loop when done
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    swap(arr[left], arr[high]);
    return left;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int main() {
    int arr[10000], n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    quickSort(arr, 0, n-1);
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
}