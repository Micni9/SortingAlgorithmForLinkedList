# Sorting Algorithm for Linked List
This project implements sorting algorithm for linked list which is originally design for array, and compares performance of different algorithm confronting different data.

All of these sorting algorithms are in-place.

## Sorting Algorithms Implemented

### 1. Selection Sort

Logic: Picks the smallest element from unsorted part and swap with the first position in the sorted part.

### 2. Insertion Sort

Logic: Iteratively picks elements from the unsorted part and inserts them into the correct position in the sorted part.

### 3. Merge Sort

Logic: Recursively splits the list into two halves, sorts them, and merges them back.

### 4. Quick Sort

Logic: Recursively splits the list into two parts by a pivot and sorts them.

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