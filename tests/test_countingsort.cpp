#include <gtest/gtest.h>
#include "../src/algorithms/countingsort.h"

TEST(CountingSortTest, HandlesUnsortedInput) {
    std::vector<int> input = {4, 2, 2, 8, 3, 3, 1};
    std::vector<int> expected = {1, 2, 2, 3, 3, 4, 8};
    countingSort(input);
    EXPECT_EQ(input, expected);
}

TEST(CountingSortTest, HandlesAlreadySortedInput) {
    std::vector<int> input = {1, 2, 3, 4, 5};
    std::vector<int> expected = {1, 2, 3, 4, 5};
    countingSort(input);
    EXPECT_EQ(input, expected);
}

TEST(CountingSortTest, HandlesReverseSortedInput) {
    std::vector<int> input = {5, 4, 3, 2, 1};
    std::vector<int> expected = {1, 2, 3, 4, 5};
    countingSort(input);
    EXPECT_EQ(input, expected);
}

TEST(CountingSortTest, HandlesDuplicates) {
    std::vector<int> input = {3, 3, 2, 1, 2, 1};
    std::vector<int> expected = {1, 1, 2, 2, 3, 3};
    countingSort(input);
    EXPECT_EQ(input, expected);
}

TEST(CountingSortTest, HandlesEmptyInput) {
    std::vector<int> input = {};
    std::vector<int> expected = {};
    countingSort(input);
    EXPECT_EQ(input, expected);
}