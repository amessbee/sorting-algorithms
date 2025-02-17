#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include "../src/bubble_sort.h"
#include "../src/insertion_sort.h"
#include "../src/selection_sort.h"
#include "../src/merge_sort.h"
#include "../src/quick_sort.h"

using namespace std;
using namespace std::chrono;

vector<int> generate_random_vector(int size) {
    vector<int> vec(size);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10000);
    
    for(int i = 0; i < size; i++) {
        vec[i] = dis(gen);
    }
    return vec;
}

void test_sort_algorithm(void (*sort_func)(vector<int>&), const string& name, vector<int>& numbers) {
    vector<int> test_vec = numbers;  // Create a copy to sort
    
    auto start = high_resolution_clock::now();
    sort_func(test_vec);
    auto stop = high_resolution_clock::now();
    
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << name << " took " << duration.count() << " milliseconds" << endl;
}

int main() {
    const int sizes[] = {1000, 5000, 10000};
    
    for(int size : sizes) {
        cout << "\nTesting with array size: " << size << endl;
        cout << "----------------------------------------" << endl;
        
        vector<int> numbers = generate_random_vector(size);
        
        test_sort_algorithm(bubble_sort, "Bubble Sort", numbers);
        test_sort_algorithm(insertion_sort, "Insertion Sort", numbers);
        test_sort_algorithm(selection_sort, "Selection Sort", numbers);
        test_sort_algorithm(merge_sort, "Merge Sort", numbers);
        test_sort_algorithm(quick_sort, "Quick Sort", numbers);
    }
    
    return 0;
}