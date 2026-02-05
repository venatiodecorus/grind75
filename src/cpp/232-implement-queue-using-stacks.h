#ifndef IMPLEMENT_QUEUE_USING_STACKS_H
#define IMPLEMENT_QUEUE_USING_STACKS_H

#include <stack>

class MyQueue {
private:
    std::stack<int> stack1;
    std::stack<int> stack2;
    
public:
    MyQueue();
    
    void push(int x);
    
    int pop();
    
    int peek();
    
    bool empty();
};

#endif // IMPLEMENT_QUEUE_USING_STACKS_H
