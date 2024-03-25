void bubble_sort(int arr[], int len) {
    // loop thru len-times to make sure all elements are sorted
    for (int i = 0; i < len; ++i) {
        // inner loop goes thru one iteration of the sort
        // NOTE: we subtract i since after each iteration the last i-elements are sorted
        for (int j = 0; j < len - 1 - i; ++j) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
