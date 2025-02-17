#include "bucketsort.h"
#include <algorithm>
#include <vector>

void bucketSort(std::vector<int>& arr) {
    if (arr.empty()) return;
    
    // Find max value to determine bucket range
    int maxVal = *std::max_element(arr.begin(), arr.end());
    
    // Create buckets
    std::vector<std::vector<int>> buckets(arr.size());
    
    // Distribute elements into buckets
    for (int i = 0; i < arr.size(); i++) {
        int bucketIndex = (arr.size() * arr[i]) / (maxVal + 1);
        buckets[bucketIndex].push_back(arr[i]);
    }
    
    // Sort individual buckets
    for (auto& bucket : buckets) {
        std::sort(bucket.begin(), bucket.end());
    }
    
    // Concatenate all buckets into original array
    int index = 0;
    for (const auto& bucket : buckets) {
        for (int value : bucket) {
            arr[index++] = value;
        }
    }
}
