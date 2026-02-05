#include <gtest/gtest.h>
#include "232-implement-queue-using-stacks.h"

TEST(MyQueueTest, Example1) {
    // Input:
    // ["MyQueue", "push", "push", "peek", "pop", "empty"]
    // [[], [1], [2], [], [], []]
    // Output:
    // [null, null, null, 1, 1, false]
    
    MyQueue* myQueue = new MyQueue();
    myQueue->push(1);              // queue is: [1]
    myQueue->push(2);              // queue is: [1, 2] (leftmost is front of the queue)
    EXPECT_EQ(myQueue->peek(), 1); // return 1
    EXPECT_EQ(myQueue->pop(), 1);  // return 1, queue is [2]
    EXPECT_FALSE(myQueue->empty()); // return false
    
    delete myQueue;
}

TEST(MyQueueTest, BasicOperations) {
    MyQueue* myQueue = new MyQueue();
    
    EXPECT_TRUE(myQueue->empty());
    
    myQueue->push(1);
    EXPECT_FALSE(myQueue->empty());
    EXPECT_EQ(myQueue->peek(), 1);
    
    myQueue->push(2);
    myQueue->push(3);
    EXPECT_EQ(myQueue->peek(), 1);
    
    EXPECT_EQ(myQueue->pop(), 1);
    EXPECT_EQ(myQueue->peek(), 2);
    
    EXPECT_EQ(myQueue->pop(), 2);
    EXPECT_EQ(myQueue->pop(), 3);
    
    EXPECT_TRUE(myQueue->empty());
    
    delete myQueue;
}

TEST(MyQueueTest, InterleavedOperations) {
    MyQueue* myQueue = new MyQueue();
    
    myQueue->push(1);
    myQueue->push(2);
    EXPECT_EQ(myQueue->pop(), 1);
    
    myQueue->push(3);
    myQueue->push(4);
    EXPECT_EQ(myQueue->pop(), 2);
    
    myQueue->push(5);
    EXPECT_EQ(myQueue->peek(), 3);
    EXPECT_EQ(myQueue->pop(), 3);
    EXPECT_EQ(myQueue->pop(), 4);
    EXPECT_EQ(myQueue->pop(), 5);
    
    EXPECT_TRUE(myQueue->empty());
    
    delete myQueue;
}

TEST(MyQueueTest, SingleElement) {
    MyQueue* myQueue = new MyQueue();
    
    myQueue->push(42);
    EXPECT_EQ(myQueue->peek(), 42);
    EXPECT_EQ(myQueue->pop(), 42);
    EXPECT_TRUE(myQueue->empty());
    
    delete myQueue;
}

TEST(MyQueueTest, MultipleElements) {
    MyQueue* myQueue = new MyQueue();
    
    for (int i = 1; i <= 5; i++) {
        myQueue->push(i);
    }
    
    for (int i = 1; i <= 5; i++) {
        EXPECT_EQ(myQueue->peek(), i);
        EXPECT_EQ(myQueue->pop(), i);
    }
    
    EXPECT_TRUE(myQueue->empty());
    
    delete myQueue;
}
