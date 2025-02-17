void countingSort(int arr[], int size, int exp);
void radixSort(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, size, exp);
    }
}

void countingSort(int arr[], int size, int exp) {
    int output[size];
    int count[10] = {0};

    for (int i = 0; i < size; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
}