void countingSort(int arr[], int size) {
    int output[size]; // output array
    int count[256] = {0}; // count array

    // Store the count of each character
    for (int i = 0; i < size; ++i) {
        count[arr[i]]++;
    }

    // Change count[i] so that it contains the actual position of this character in output[]
    for (int i = 1; i <= 255; ++i) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = size - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the output array to arr[], so that arr[] now contains sorted characters
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
}