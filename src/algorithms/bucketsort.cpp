void bucketSort(int arr[], int n) {
    // Find the maximum element in the array
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    // Create buckets
    int bucketCount = maxVal / 10 + 1; // Assuming bucket size of 10
    std::vector<std::vector<int>> buckets(bucketCount);

    // Distribute input array values into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] / 10;
        buckets[bucketIndex].push_back(arr[i]);
    }

    // Sort individual buckets and concatenate
    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        std::sort(buckets[i].begin(), buckets[i].end());
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
}#include "bucketsort.h"
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
