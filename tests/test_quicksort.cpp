#include "quicksort.h"
#include <gtest/gtest.h>
#include <vector>

TEST(QuickSortTest, HandlesEmptyArray) {
    std::vector<int> arr = {};
    quickSort(arr);
    EXPECT_TRUE(arr.empty());
}

TEST(QuickSortTest, HandlesSingleElement) {
    std::vector<int> arr = {1};
    quickSort(arr);
    EXPECT_EQ(arr, std::vector<int>({1}));
}

TEST(QuickSortTest, HandlesSortedArray) {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    quickSort(arr);
    EXPECT_EQ(arr, std::vector<int>({1, 2, 3, 4, 5}));
}

TEST(QuickSortTest, HandlesReverseSortedArray) {
    std::vector<int> arr = {5, 4, 3, 2, 1};
    quickSort(arr);
    EXPECT_EQ(arr, std::vector<int>({1, 2, 3, 4, 5}));
}

TEST(QuickSortTest, HandlesUnsortedArray) {
    std::vector<int> arr = {3, 5, 2, 1, 4};
    quickSort(arr);
    EXPECT_EQ(arr, std::vector<int>({1, 2, 3, 4, 5}));
}

TEST(QuickSortTest, HandlesArrayWithDuplicates) {
    std::vector<int> arr = {3, 1, 2, 3, 4, 3, 5};
    quickSort(arr);
    EXPECT_EQ(arr, std::vector<int>({1, 2, 3, 3, 3, 4, 5}));
}