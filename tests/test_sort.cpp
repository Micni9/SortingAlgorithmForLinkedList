#include "../include/sortings.h"
#include "../include/sortings.h"

#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> vec = {4, 2, 1, 3};
    ListNode *head = create_list(vec);
    cout<<"Original list: ";
    print_list(head);
    selection_sort(head);
    cout<<"After selection sort: ";
    print_list(head);
    return 0;
}