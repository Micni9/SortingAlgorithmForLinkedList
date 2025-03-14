#ifndef LIST_NODE_H
#define LIST_NODE_H

#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* create_list(std::vector<int> &vec);
void print_list(ListNode *head);
bool is_sorted(ListNode *head);

#endif