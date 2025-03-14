#include "list_node.h"
#include "sortings.h"
#include <iostream>
using namespace std;

void bubble_sort(ListNode*& head){
    if(head == nullptr || head->next == nullptr) return;
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* tail = nullptr;
    while(tail != dummy->next){
        ListNode* pre = dummy;
        while(pre->next->next != tail){
            ListNode* current = pre->next;
            if(current->val > current->next->val){
                pre->next = current->next;
                current->next = current->next->next;
                pre->next->next = current;
            }
            pre = pre->next;
        }
        tail = pre->next;
    }
    head = dummy->next;
    delete dummy;
}