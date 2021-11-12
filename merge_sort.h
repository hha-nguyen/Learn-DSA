#ifndef merge_sort
#define merge_sort

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
        if (leftArray[indexofSubArrayOne] <= rightArray[indexofSubArrayTwo]) {
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

#endif
