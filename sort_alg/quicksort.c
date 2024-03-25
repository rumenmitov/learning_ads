void swap(int* a, int* b) {
    const int swp = *b;
    *b = *a;
    *a = swp;
}


/*
 * Partition function puts all elements lower than the pivot on the left,
 * and all elements higher than the pivot on the right. It then returns
 * the new index of the pivot so that we know where the divide is.
 */
int partition(int* arr, int len, int low, int high) {
    // IMPORTANT: setting pivot to the last element could cause a runtime of O(n^2) in a reverse sort scenario
    const int pivot = arr[high];

    // index only increments once we find a value lower than our pivot
    int index = low - 1;

    for (int i = low; i < high; ++i) {
        if (arr[i] < pivot) {
            // increment index since we are adding a value lower than pivot
            index++;

            // swap value at index and current value
            swap(arr + index, arr + i);
        }
        
    }

    // finally increment index to swap the next element with the pivot
    index++;
    swap(arr + index, arr + high);

    // return index of where the pivot value is (it will be used to know where to split)
    return index;
}

void sort(int* arr, int len, int low, int high) {
    if (low >= high) return;

    const int pivotIndex = partition(arr, len, low, high);

    sort(arr, len, low, pivotIndex - 1); // repeat quicksort for lower part of array
    sort(arr, len, pivotIndex + 1, high); // repeat quicksort for upper part of array
}

void quicksort(int* arr, int len) {
    sort(arr, len, 0, len - 1);
}
