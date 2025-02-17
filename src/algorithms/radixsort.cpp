#include "radixsort.h"
#include <algorithm>

void countSort(std::vector<int>& arr, int exp) {
    std::vector<int> output(arr.size());
    std::vector<int> count(10, 0);
    
    // Store count of occurrences
    for (int i = 0; i < arr.size(); i++)
        count[(arr[i] / exp) % 10]++;
    
    // Change count[i] to contain actual position
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    
    // Build the output array
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    
    arr = output;
}

void radixSort(std::vector<int>& arr) {
    if (arr.empty()) return;
    
    // Find the maximum number to know number of digits
    int maxNum = *std::max_element(arr.begin(), arr.end());
    
    // Do counting sort for every digit
    for (int exp = 1; maxNum / exp > 0; exp *= 10)
        countSort(arr, exp);
}
