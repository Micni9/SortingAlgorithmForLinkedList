#include "list_node.h"
#include "sortings.h"
#include <vector>
#include <chrono>
#include <fstream>
#include <iostream>
using namespace std;

ListNode* generate_random_list(int size, int min, int max) {
    vector<int> vec(size);
    for (int i = 0; i < size; i++) {
        vec[i] = rand() % (max - min + 1) + min;
    }
    return create_list(vec);
}

ListNode* copyList(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    ListNode* p = head;
    while (p) {
        current->next = new ListNode(p->val);
        current = current->next;
        p = p->next;
    }
    return dummy->next;
}

ListNode* generate_descending_list(int size){
    vector<int> vec(size);
    for(int i = 0; i < size; i++){
        vec[i] = size - i;
    }
    return create_list(vec);
}

ListNode* generate_ascending_list(int size){
    vector<int> vec(size);
    for(int i = 0; i < size; i++){
        vec[i] = i;
    }
    return create_list(vec);
}

ListNode* generate_same_list(int size, int val){
    vector<int> vec(size, val);
    return create_list(vec);
}

ListNode* generate_almost_sorted_list(int size, int swapTimes){
    vector<int> vec(size);
    for(int i = 0; i < size; i++){
        vec[i] = i;
    }
    for(int i = 0; i < swapTimes; i++){
        int index1 = rand()%size;
        int index2 = rand()%size;
        swap(vec[index1], vec[index2]);
    }
    return create_list(vec);
}

void benchmarkSortingAlgorithm(void (*sortingAlgorithm)(ListNode*&), ListNode* list, const string& algorithmName, ofstream& fout) {
    fout << algorithmName << ": ";

    // Start the timer
    auto startTime = chrono::high_resolution_clock::now();

    // Run the sorting algorithm
    sortingAlgorithm(list);

    // Stop the timer
    auto endTime = chrono::high_resolution_clock::now();

    // Calculate the elapsed time
    chrono::duration<double> elapsedTime = endTime - startTime;

    // Output the elapsed time
    fout << "Elapsed time: " << elapsedTime.count() << " seconds" << endl;
}

int main() {
    int listSize; // Adjust the size as needed
    cout<<"Enter the size of the list: ";
    cin>>listSize;

    // Generate random, descending, and ascending lists
    ListNode* list1 = generate_random_list(listSize,-1000,1000);
    ListNode* list2 = generate_descending_list(listSize);
    ListNode* list3 = generate_ascending_list(listSize);
    ListNode* list4 = generate_same_list(listSize, 1);
    ListNode* list5 = generate_almost_sorted_list(listSize, 5);

    ofstream fout("benchmark.txt");
    if(!fout){
        cout<<"Cannot open the file"<<endl;
        return 1;
    }
    fout<<"List size: "<<listSize<<endl;

    // Benchmark for random list
    fout<<"\nRandom list: "<<endl;
    benchmarkSortingAlgorithm(selection_sort, copyList(list1), "Selection Sort",fout);
    benchmarkSortingAlgorithm(insertion_sort, copyList(list1), "Insertion Sort",fout);
    benchmarkSortingAlgorithm(merge_sort, copyList(list1), "Merge Sort",fout);
    benchmarkSortingAlgorithm(bubble_sort, copyList(list1), "Bubble Sort",fout);
    benchmarkSortingAlgorithm(quick_sort, copyList(list1), "Quick Sort",fout);

    // Benchmark for descending list
    fout<<"\nDescending list: "<<endl;
    benchmarkSortingAlgorithm(selection_sort, copyList(list2), "Selection Sort",fout);
    benchmarkSortingAlgorithm(insertion_sort, copyList(list2), "Insertion Sort",fout);
    benchmarkSortingAlgorithm(bubble_sort, copyList(list2), "Bubble Sort",fout);
    benchmarkSortingAlgorithm(merge_sort, copyList(list2), "Merge Sort",fout);
    benchmarkSortingAlgorithm(quick_sort, copyList(list2), "Quick Sort",fout);

    // Benchmark for ascending list
    fout<<"\nAscending list: "<<endl;
    benchmarkSortingAlgorithm(selection_sort, copyList(list3), "Selection Sort",fout);
    benchmarkSortingAlgorithm(insertion_sort, copyList(list3), "Insertion Sort",fout);
    benchmarkSortingAlgorithm(bubble_sort, copyList(list3), "Bubble Sort",fout);
    benchmarkSortingAlgorithm(merge_sort, copyList(list3), "Merge Sort",fout);
    benchmarkSortingAlgorithm(quick_sort, copyList(list3), "Quick Sort",fout);

    // Benchmark for same list
    fout<<"\nSame list: "<<endl;
    benchmarkSortingAlgorithm(selection_sort, copyList(list4), "Selection Sort",fout);
    benchmarkSortingAlgorithm(insertion_sort, copyList(list4), "Insertion Sort",fout);
    benchmarkSortingAlgorithm(bubble_sort, copyList(list4), "Bubble Sort",fout);
    benchmarkSortingAlgorithm(merge_sort, copyList(list4), "Merge Sort",fout);
    benchmarkSortingAlgorithm(quick_sort, copyList(list4), "Quick Sort",fout);

    // Benchmark for almost sorted list
    fout<<"\nAlmost sorted list: "<<endl;
    benchmarkSortingAlgorithm(selection_sort, copyList(list5), "Selection Sort",fout);
    benchmarkSortingAlgorithm(insertion_sort, copyList(list5), "Insertion Sort",fout);
    benchmarkSortingAlgorithm(bubble_sort, copyList(list5), "Bubble Sort",fout);
    benchmarkSortingAlgorithm(merge_sort, copyList(list5), "Merge Sort",fout);
    benchmarkSortingAlgorithm(quick_sort, copyList(list5), "Quick Sort",fout);

    fout.close();
    cout<<"Benchmarking completed. Please check the benchmark.txt file for the results."<<endl;

    return 0;
}