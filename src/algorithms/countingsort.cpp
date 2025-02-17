#include "countingsort.h"
#include <algorithm>

void countingSort(std::vector<int>& arr, int maxVal) {
    std::vector<int> count(maxVal + 1, 0);
    std::vector<int> output(arr.size());
    
    // Store count of each element
    for (int i = 0; i < arr.size(); i++)
        count[arr[i]]++;
    
    // Change count[i] to contain actual position
    for (int i = 1; i <= maxVal; i++)
        count[i] += count[i - 1];
    
    // Build the output array
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    
    arr = output;
}
