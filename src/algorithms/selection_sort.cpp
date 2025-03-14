// Instead of swapping the elements, we just change the pointer of the elements
#include "list_node.h"
#include "sortings.h"

void selection_sort(ListNode*& head){
    if(head == nullptr || head->next == nullptr) return;
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* current = head;
    ListNode* pre = dummy;
    while(current){
        ListNode* min = current;
        ListNode* min_pre = pre;
        ListNode* temp = current->next;
        ListNode* temp_pre = current;
        while(temp){
            if(temp->val < min->val){
                min = temp;
                min_pre = temp_pre;
            }
            temp_pre = temp;
            temp = temp->next;
        }
        if(min != current){
            min_pre->next = min->next;
            pre->next = min;
            min->next = current;
            pre = min;
        }
        else{
            pre = current;
            current = current->next;
        }
    }
    head = dummy->next;
    delete dummy;
}