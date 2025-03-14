#include "list_node.h"
#include "sortings.h"
#include <iostream>
using namespace std;

ListNode* partition(ListNode* dummy, ListNode* tail){
    ListNode* pivot = dummy->next;
    ListNode* current = pivot->next;
    ListNode* pre = pivot;
    while(current != tail){
        if(current->val < pivot->val){
            pre->next = current->next;
            current->next = dummy->next;
            dummy->next = current;
            current = pre->next;
        }
        else{
            pre = current;
            current = current->next;
        }
    }
    return pivot;
}

void quick_sort_helper(ListNode* dummy, ListNode* tail){
    if(dummy->next == nullptr || dummy->next->next == tail) return;

    ListNode* pivot = partition(dummy,tail);
    if(dummy->next!=pivot)
    quick_sort_helper(dummy, pivot);
    if(pivot->next!=tail)
    quick_sort_helper(pivot, tail);
}

void quick_sort(ListNode*& head){
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    quick_sort_helper(dummy, nullptr);
    head = dummy->next;
    delete dummy;
}