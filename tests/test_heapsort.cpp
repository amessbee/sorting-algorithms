#include <gtest/gtest.h>
#include "../src/algorithms/heapsort.h"

TEST(HeapSortTest, HandlesUnsortedArray) {
    std::vector<int> arr = {3, 5, 1, 4, 2};
    heapSort(arr);
    EXPECT_EQ(arr, std::vector<int>({1, 2, 3, 4, 5}));
}

TEST(HeapSortTest, HandlesAlreadySortedArray) {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    heapSort(arr);
    EXPECT_EQ(arr, std::vector<int>({1, 2, 3, 4, 5}));
}

TEST(HeapSortTest, HandlesReverseSortedArray) {
    std::vector<int> arr = {5, 4, 3, 2, 1};
    heapSort(arr);
    EXPECT_EQ(arr, std::vector<int>({1, 2, 3, 4, 5}));
}

TEST(HeapSortTest, HandlesSingleElement) {
    std::vector<int> arr = {42};
    heapSort(arr);
    EXPECT_EQ(arr, std::vector<int>({42}));
}

TEST(HeapSortTest, HandlesEmptyArray) {
    std::vector<int> arr = {};
    heapSort(arr);
    EXPECT_EQ(arr, std::vector<int>({}));
}