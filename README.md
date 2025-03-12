# Sorting Algorithm for Linked List
This project implements sorting algorithm for linked list which is originally design for array, and compares performance of different algorithm confronting different data.

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

/sorting_analysis_project
│── /sorting_algorithms
│   │── __init__.py
│   │── insertion_sort.py
│   │── merge_sort.py
│   │── quick_sort.py
│── analysis.ipynb  # Jupyter Notebook for benchmarking & visualization
│── generate_data.py  # Utility to create test data
│── README.md  # Project documentation

## How to Run

Install dependencies:

pip install numpy matplotlib

Run the Jupyter Notebook:

jupyter notebook analysis.ipynb
