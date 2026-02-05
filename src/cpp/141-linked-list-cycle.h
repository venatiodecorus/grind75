#ifndef LINKED_LIST_CYCLE_H
#define LINKED_LIST_CYCLE_H

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool hasCycle(ListNode *head);

#endif // LINKED_LIST_CYCLE_H
