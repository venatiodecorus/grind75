/**
 * 232. Implement Queue using Stacks
 * Difficulty: Easy
 * https://leetcode.com/problems/implement-queue-using-stacks
 *
 * Implement a first in first out (FIFO) queue using only two stacks.
 * The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).
 *
 * Implement the MyQueue class:
 * - void push(int x) Pushes element x to the back of the queue.
 * - int pop() Removes the element from the front of the queue and returns it.
 * - int peek() Returns the element at the front of the queue.
 * - boolean empty() Returns true if the queue is empty, false otherwise.
 *
 * Notes:
 * - You must use only standard operations of a stack, which means only push to top,
 *   peek/pop from top, size, and is empty operations are valid.
 * - Depending on your language, the stack may not be supported natively. You may simulate
 *   a stack using a list or deque (double-ended queue) as long as you use only a stack's
 *   standard operations.
 *
 * Follow-up: Can you implement the queue such that each operation is amortized O(1) time complexity?
 * In other words, performing n operations will take overall O(n) time even if one of those operations
 * may take longer.
 */

#include "232-implement-queue-using-stacks.h"

MyQueue::MyQueue() {
    // TODO: Initialize your data structure here

}

void MyQueue::push(int x) {
    // TODO: Push element x to the back of queue
    int stack2_size = stack2.size();
    for(size_t i = 0; i < stack2_size; i++) {
        stack1.push(stack2.top());
        stack2.pop();
    }

    stack2.push(x);

    // Return the values
    int stack1_size = stack1.size();
    for(size_t i = 0; i < stack1_size; i++) {
        stack2.push(stack1.top());
        stack1.pop();
    }
}

int MyQueue::pop() {
    // TODO: Removes the element from in front of queue and returns that element
    if(stack2.size() > 0) {
        int val = stack2.top();
        stack2.pop();
        return val;
    }
    return 0;
}

int MyQueue::peek() {
    // TODO: Get the front element
    if(stack2.size() > 0) {
        return stack2.top();
    }
    return 0;
}

bool MyQueue::empty() {
    // TODO: Returns whether the queue is empty
    if(stack2.size() == 0)
        return true;
    else
        return false;
}
