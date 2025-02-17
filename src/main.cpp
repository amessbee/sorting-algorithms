#include <iostream>
#include "algorithms/quicksort.h"
#include "algorithms/mergesort.h"
#include "algorithms/heapsort.h"
#include "algorithms/countingsort.h"
#include "algorithms/bucketsort.h"
#include "algorithms/radixsort.h"

int main() {
    // Example array to sort
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Demonstrating Quick Sort
    std::cout << "Original array: ";
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    quickSort(arr, 0, n - 1);
    std::cout << "Sorted array using Quick Sort: ";
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    // Resetting array for other sorting algorithms
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};

    // Demonstrating Merge Sort
    mergeSort(arr2, 0, n - 1);
    std::cout << "Sorted array using Merge Sort: ";
    for (int i = 0; i < n; i++)
        std::cout << arr2[i] << " ";
    std::cout << std::endl;

    // Additional sorting algorithms can be demonstrated similarly...

    return 0;
}