#include "list_node.h"
#include "sortings.h"
#include <queue>
using namespace std;

void merge(ListNode*& head1, ListNode*& head2){
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    while(head1 && head2){
        if(head1->val < head2->val){
            current->next = head1;
            head1 = head1->next;
        }
        else{
            current->next = head2;
            head2 = head2->next;
        }
        current = current->next;
    }
    if(head1) current->next = head1;
    if(head2) current->next = head2;
    head1 = dummy->next;
    delete dummy;
}

void merge_sort(ListNode*& head){
    if(head == nullptr || head->next == nullptr) return;
    queue<ListNode*> q;
    ListNode* current = head;
    while(current){
        ListNode* temp = current;
        current = current->next;
        temp->next = nullptr;
        q.push(temp);
    }

    while(q.size() > 1){
        ListNode* head1 = q.front();
        q.pop();
        ListNode* head2 = q.front();
        q.pop();
        merge(head1, head2);
        q.push(head1);
    }
    head = q.front();
}