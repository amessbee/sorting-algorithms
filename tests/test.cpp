#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <iomanip>
#include <algorithm>
#include "../src/algorithms/bucketsort.h"
#include "../src/algorithms/mergesort.h"
#include "../src/algorithms/quicksort.h"
#include "../src/algorithms/heapsort.h"
#include "../src/algorithms/radixsort.h"
#include "../src/algorithms/countingsort.h"

using namespace std;
using namespace std::chrono;

// Structure to store sorting results
struct SortResult {
    string name;
    vector<double> times;
    double avgTime;
};

// Generate random vector of specified size
vector<int> generateRandomVector(int size) {
    vector<int> vec(size);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 1000000);
    
    for(int i = 0; i < size; i++) {
        vec[i] = dis(gen);
    }
    return vec;
}

// Verify if array is sorted
bool isSorted(const vector<int>& arr) {
    return is_sorted(arr.begin(), arr.end());
}

// Template function to measure sorting time
template<typename Func>
double measureSortingTime(Func sortFunc, vector<int>& arr) {
    vector<int> testArr = arr;  // Create a copy
    
    auto start = high_resolution_clock::now();
    sortFunc(testArr);
    auto stop = high_resolution_clock::now();
    
    if (!isSorted(testArr)) {
        throw runtime_error("Array not properly sorted!");
    }
    
    return duration_cast<milliseconds>(stop - start).count() / 1000.0;
}

// Wrapper functions for different sorting algorithms
void testQuickSort(vector<int>& arr) {
    int* data = arr.data();
    quickSort(data, 0, arr.size() - 1);
}

void testMergeSort(vector<int>& arr) {
    int* data = arr.data();
    mergeSort(data, 0, arr.size() - 1);
}

void testHeapSort(vector<int>& arr) {
    int* data = arr.data();
    heapSort(data, arr.size());
}

int main() {
    // Test configurations
    const vector<int> sizes = {50000, 500000, 9000000};
    const int numTrials = 5;
    vector<SortResult> results;
    
    // Initialize results for each algorithm
    vector<pair<string, function<void(vector<int>&)>>> algorithms = {
        {"QuickSort", testQuickSort},
        {"MergeSort", testMergeSort},
        {"HeapSort", testHeapSort},
        // {"BucketSort", bucketSort},
        {"RadixSort", radixSort},
        {"CountingSort", [](vector<int>& arr) { countingSort(arr, 10000000); }}
    };

    for (const auto& algo : algorithms) {
        results.push_back({algo.first, vector<double>(), 0.0});
    }

    // Run tests for each size
    cout << "\nRunning performance tests...\n" << endl;
    
    for (int size : sizes) {
        cout << "Testing with array size: " << size << endl;
        cout << string(40, '-') << endl;
        
        for (int trial = 0; trial < numTrials; trial++) {
            vector<int> testData = generateRandomVector(size);
            
            for (size_t i = 0; i < algorithms.size(); i++) {
                try {
                    double time = measureSortingTime(algorithms[i].second, testData);
                    results[i].times.push_back(time);
                } catch (const exception& e) {
                    cout << "Error in " << algorithms[i].first << ": " << e.what() << endl;
                }
            }
        }
    }

    // Calculate averages and print results
    cout << "\nPerformance Summary:\n" << endl;
    cout << setw(15) << left << "Algorithm" 
         << setw(15) << right << "Avg Time (s)" << endl;
    cout << string(30, '-') << endl;

    for (auto& result : results) {
        if (!result.times.empty()) {
            result.avgTime = accumulate(result.times.begin(), result.times.end(), 0.0) / result.times.size();
            cout << setw(15) << left << result.name 
                 << setw(15) << fixed << setprecision(3) << right << result.avgTime << endl;
        }
    }

    return 0;
}
