#include <gtest/gtest.h>
#include "../src/algorithms/bucketsort.h"

TEST(BucketSortTest, HandlesSortedInput) {
    std::vector<int> input = {1, 2, 3, 4, 5};
    std::vector<int> expected = {1, 2, 3, 4, 5};
    bucketSort(input);
    EXPECT_EQ(input, expected);
}

TEST(BucketSortTest, HandlesReverseSortedInput) {
    std::vector<int> input = {5, 4, 3, 2, 1};
    std::vector<int> expected = {1, 2, 3, 4, 5};
    bucketSort(input);
    EXPECT_EQ(input, expected);
}

TEST(BucketSortTest, HandlesUnsortedInput) {
    std::vector<int> input = {3, 1, 4, 2, 5};
    std::vector<int> expected = {1, 2, 3, 4, 5};
    bucketSort(input);
    EXPECT_EQ(input, expected);
}

TEST(BucketSortTest, HandlesEmptyInput) {
    std::vector<int> input = {};
    std::vector<int> expected = {};
    bucketSort(input);
    EXPECT_EQ(input, expected);
}

TEST(BucketSortTest, HandlesSingleElementInput) {
    std::vector<int> input = {42};
    std::vector<int> expected = {42};
    bucketSort(input);
    EXPECT_EQ(input, expected);
}