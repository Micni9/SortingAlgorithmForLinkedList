#include "list_node.h"
#include "sortings.h"
#include <queue>
using namespace std;

void MI_sort(ListNode*& head){
    ListNode* right = head;
    ListNode* p = right->next;

    queue<ListNode*> q;
    q.push(head);
    while (p) {
        if (p->val < right->val) {
            q.push(p);
            right->next = nullptr;
        }
        right = p;
        p = p->next;
    }

    while(q.size()>1){
        ListNode* head1 = q.front();
        q.pop();
        ListNode* head2 = q.front();
        q.pop();
        merge(head1, head2);
        q.push(head1);
    }
    head = q.front();
}