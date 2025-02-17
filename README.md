# Sorting Algorithms Project

This project implements various sorting algorithms in C++. The following algorithms are included:

- Quick Sort
- Merge Sort
- Heap Sort
- Counting Sort
- Bucket Sort
- Radix Sort

## Project Structure

```
sorting-algorithms
├── src
│   ├── main.cpp
│   ├── algorithms
│   │   ├── quicksort.cpp
│   │   ├── quicksort.h
│   │   ├── mergesort.cpp
│   │   ├── mergesort.h
│   │   ├── heapsort.cpp
│   │   ├── heapsort.h
│   │   ├── countingsort.cpp
│   │   ├── countingsort.h
│   │   ├── bucketsort.cpp
│   │   ├── bucketsort.h
│   │   ├── radixsort.cpp
│   │   └── radixsort.h
├── tests
│   ├── test_quicksort.cpp
│   ├── test_mergesort.cpp
│   ├── test_heapsort.cpp
│   ├── test_countingsort.cpp
│   ├── test_bucketsort.cpp
│   └── test_radixsort.cpp
├── CMakeLists.txt
└── README.md
```

## Building the Project

To build the project, navigate to the project directory and run the following commands:

```bash
mkdir build
cd build
cmake ..
make
```

## Running the Algorithms

After building, you can run the main application to see the sorting algorithms in action:

```bash
./sorting-algorithms
```

## Running Tests

To run the tests, you can use the following command after building:

```bash
./tests/test_suite
```

## Contributing

Feel free to contribute by adding new algorithms or improving existing ones. Please ensure that you include tests for any new functionality.