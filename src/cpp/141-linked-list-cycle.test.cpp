#include <gtest/gtest.h>
#include "141-linked-list-cycle.h"

// Helper function to create a linked list with a cycle at pos
ListNode* createLinkedListWithCycle(const std::vector<int>& values, int pos) {
    if (values.empty()) return nullptr;
    
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    ListNode* cycleNode = nullptr;
    
    if (pos == 0) cycleNode = head;
    
    for (size_t i = 1; i < values.size(); i++) {
        current->next = new ListNode(values[i]);
        current = current->next;
        if (i == pos) cycleNode = current;
    }
    
    // Create cycle if pos is valid
    if (pos != -1 && cycleNode != nullptr) {
        current->next = cycleNode;
    }
    
    return head;
}

// Helper function to delete linked list (without cycle)
void deleteLinkedList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// Helper function to delete linked list with cycle
void deleteLinkedListWithCycle(ListNode* head, int pos) {
    if (!head) return;
    
    if (pos == -1) {
        deleteLinkedList(head);
        return;
    }
    
    // Break the cycle first
    ListNode* current = head;
    int count = 0;
    while (current->next) {
        if (count == pos + static_cast<int>(std::vector<int>{}.size())) {
            current->next = nullptr;
            break;
        }
        current = current->next;
        count++;
    }
    
    deleteLinkedList(head);
}

// Better helper to delete with cycle - find the cycle and break it
void deleteLinkedListSafe(ListNode* head, bool hasCycleExpected) {
    if (!head) return;
    
    if (!hasCycleExpected) {
        deleteLinkedList(head);
        return;
    }
    
    // Use Floyd's algorithm to find cycle
    ListNode* slow = head;
    ListNode* fast = head;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }
    
    if (fast && fast->next) {
        // Find the start of cycle and break it
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        // Now slow/fast is at cycle start, find the node before it
        ListNode* temp = slow;
        while (temp->next != slow) {
            temp = temp->next;
        }
        temp->next = nullptr;
    }
    
    deleteLinkedList(head);
}

TEST(LinkedListCycleTest, Example1) {
    // Input: head = [3,2,0,-4], pos = 1
    // Output: true
    // Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
    ListNode* head = createLinkedListWithCycle({3, 2, 0, -4}, 1);
    
    EXPECT_TRUE(hasCycle(head));
    
    deleteLinkedListSafe(head, true);
}

TEST(LinkedListCycleTest, Example2) {
    // Input: head = [1,2], pos = 0
    // Output: true
    // Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
    ListNode* head = createLinkedListWithCycle({1, 2}, 0);
    
    EXPECT_TRUE(hasCycle(head));
    
    deleteLinkedListSafe(head, true);
}

TEST(LinkedListCycleTest, Example3) {
    // Input: head = [1], pos = -1
    // Output: false
    // Explanation: There is no cycle in the linked list.
    ListNode* head = createLinkedListWithCycle({1}, -1);
    
    EXPECT_FALSE(hasCycle(head));
    
    deleteLinkedListSafe(head, false);
}

TEST(LinkedListCycleTest, EmptyList) {
    // Input: head = [], pos = -1
    // Output: false
    ListNode* head = nullptr;
    
    EXPECT_FALSE(hasCycle(head));
}

TEST(LinkedListCycleTest, TwoNodesCycle) {
    // Input: head = [1,2], pos = 0
    // Output: true
    ListNode* head = createLinkedListWithCycle({1, 2}, 0);
    
    EXPECT_TRUE(hasCycle(head));
    
    deleteLinkedListSafe(head, true);
}

TEST(LinkedListCycleTest, LongListNoCycle) {
    // Input: head = [1,2,3,4,5,6,7,8,9,10], pos = -1
    // Output: false
    ListNode* head = createLinkedListWithCycle({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, -1);
    
    EXPECT_FALSE(hasCycle(head));
    
    deleteLinkedListSafe(head, false);
}
