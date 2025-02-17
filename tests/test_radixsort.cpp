#include <iostream>
#include <vector>
#include "radixsort.h"

void testRadixSort() {
    std::vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    std::vector<int> expected = {2, 24, 45, 66, 75, 90, 170, 802};

    radixSort(arr);

    if (arr == expected) {
        std::cout << "Radix Sort Test Passed!" << std::endl;
    } else {
        std::cout << "Radix Sort Test Failed!" << std::endl;
    }
}

int main() {
    testRadixSort();
    return 0;
}