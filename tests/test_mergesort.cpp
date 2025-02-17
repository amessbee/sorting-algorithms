#include <gtest/gtest.h>
#include "../src/algorithms/mergesort.h"

TEST(MergeSortTest, HandlesSortedArray) {
    std::vector<int> input = {1, 2, 3, 4, 5};
    std::vector<int> expected = {1, 2, 3, 4, 5};
    mergeSort(input);
    EXPECT_EQ(input, expected);
}

TEST(MergeSortTest, HandlesReverseSortedArray) {
    std::vector<int> input = {5, 4, 3, 2, 1};
    std::vector<int> expected = {1, 2, 3, 4, 5};
    mergeSort(input);
    EXPECT_EQ(input, expected);
}

TEST(MergeSortTest, HandlesUnsortedArray) {
    std::vector<int> input = {3, 1, 4, 2, 5};
    std::vector<int> expected = {1, 2, 3, 4, 5};
    mergeSort(input);
    EXPECT_EQ(input, expected);
}

TEST(MergeSortTest, HandlesEmptyArray) {
    std::vector<int> input = {};
    std::vector<int> expected = {};
    mergeSort(input);
    EXPECT_EQ(input, expected);
}

TEST(MergeSortTest, HandlesSingleElementArray) {
    std::vector<int> input = {42};
    std::vector<int> expected = {42};
    mergeSort(input);
    EXPECT_EQ(input, expected);
}