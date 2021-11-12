#include <iostream>
using namespace std;
int sum(int n) {
    int sum = 0, temp;
    while (n>=1) {
        temp = n%10;
        sum += temp;
        n /= 10;
    }
    return sum;
}

void merge(int arr[], int const left, int const mid, int const right) {
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    //create temp array
    auto *leftArray = new int[subArrayOne];
    auto *rightArray = new int[subArrayTwo];

    //copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; ++i) {
        leftArray[i] = arr[left+i];
    }
    for (auto i = 0; i < subArrayTwo; ++i) {
        rightArray[i] = arr[mid+1+i];
    }

    auto indexofSubArrayOne = 0; //Intitial index of first sub-array
    auto indexofSubArrayTwo = 0; //Intitial index of second sub-array
    int indexofMergeArray = left;

    //Merge the temp array back to array[left..right]
    while (indexofSubArrayOne < subArrayOne && indexofSubArrayTwo < subArrayTwo) {
        if (sum(leftArray[indexofSubArrayOne]) < sum(rightArray[indexofSubArrayTwo]) || (sum(leftArray[indexofSubArrayOne]) == sum(rightArray[indexofSubArrayTwo]) && leftArray[indexofSubArrayOne] <= rightArray[indexofSubArrayTwo])) {
            arr[indexofMergeArray] = leftArray[indexofSubArrayOne];
            indexofSubArrayOne++;
        } else {
            arr[indexofMergeArray] = rightArray[indexofSubArrayTwo];
            indexofSubArrayTwo++;
        }
        indexofMergeArray++;
    }

    //copy remain ele of left[] if there are any
    while (indexofSubArrayOne < subArrayOne) {
        arr[indexofMergeArray] = leftArray[indexofSubArrayOne];
        indexofSubArrayOne++;
        indexofMergeArray++;
    }

    while (indexofMergeArray < subArrayTwo) {
        arr[indexofMergeArray] = rightArray[indexofSubArrayTwo];
        indexofSubArrayTwo++;
        indexofMergeArray++;
    }
}

void mergeSort(int array[], int const begin, int const end) {
    if (begin >= end) return;
    auto mid = begin + (end-begin) /2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid+1, end);
    merge(array, begin, mid, end);
}

int main() {
    int arr[10000], n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    mergeSort(arr, 0, n-1);
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << endl;
    }
}
