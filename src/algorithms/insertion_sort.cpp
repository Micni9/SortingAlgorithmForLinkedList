#include "list_node.h"
#include "sortings.h"

void insertion_sort(ListNode*& head){
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* right = head;
    ListNode* p = right->next;
    while (p) {
        if (p->val < right->val) {
            right->next = p->next;
            
            ListNode* pre = dummy;
            while (pre->next->val < p->val) {
                pre = pre->next;
            }

            p->next = pre->next;
            pre->next = p;
            p = right->next;
        }
        else {
            right = p;
            p = p->next;
        }
    }
    head = dummy->next;
    delete dummy;
}