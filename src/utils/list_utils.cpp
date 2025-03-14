#include "list_node.h"
#include <iostream>
#include <vector>

ListNode* create_list(std::vector<int> &vec) {
    if(vec.empty()) return nullptr;
    ListNode *head = new ListNode(vec[0]);
    ListNode *p = head;
    for (int i = 1; i < vec.size(); i++) {
        p->next = new ListNode(vec[i]);
        p = p->next;
    }
    return head;
}

void print_list(ListNode *head) {
    ListNode *p = head;
    while (p) {
        std::cout << p->val << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

bool is_sorted(ListNode* head) {
    if (!head || !head->next) return true;
    ListNode* p = head;
    while (p->next) {
        if (p->val > p->next->val) {
            return false;
        }
        p = p->next;
    }
    return true;
}