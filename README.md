# Sorting Algorithm for Linked List
This project implements sorting algorithm for linked list which is originally design for array, and compares performance of different algorithm confronting different data. An sorting algorithm inspired by insertion and merge sort is implemented and tests for the performance.

All of these sorting algorithms are in-place.

## Sorting Algorithms Implemented

### 1. Selection Sort

Logic: Picks the smallest element from unsorted part and swap with the first position in the sorted part.

### 2. Insertion Sort

Logic: Iteratively picks elements from the unsorted part and inserts them into the correct position in the sorted part.

### 3. Bubble Sort

Logic: Comparing two adjacent nodes, moving largest node to the tail and repeat.

### 4. Merge Sort

Logic: Recursively splits the list into two halves, sorts them, and merges them back.

### 5. Quick Sort

Logic: Recursively splits the list into two parts by a pivot and sorts them.

### 6. MI Sort

Logic: A combination of merge sort and insertion sort. Use insertion if the list is increasing, while merge the first 2 increasing list if the list is not sorted.

## Project Structure

```
/SortingAlgorithmForLinkedList
|── /include
|   |── list_node.h # Definition of ListNode structure
|   |── sortings.h # Declaration of all implemented sorting methods
│── /src
|   |── /algorithms
│   │   |── selection_sort.cpp
│   │   |── insertion_sort.cpp
|   |   |── bubble_sort.cpp
│   │   |── merge_sort.cpp
│   │   |── quick_sort.cpp
|   |   |── MI_sort.cpp
|   |── /utils
|   |   |── list_utils.cpp
|   |── benchmark.cpp
|   |── main.cpp
|── CMakeLists.txt
│── README.md  # Project documentation
```

## How to Run

Navigate to the build directory
```sh
if not exist "build" mkdir build
cd build
```
Generate build files using CMake
```sh
cmake ..
```

Build the project using '''cmake --build'''
```sh
cmake --build .
```