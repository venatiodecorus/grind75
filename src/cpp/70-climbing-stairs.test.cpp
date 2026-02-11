#include <gtest/gtest.h>
#include "70-climbing-stairs.h"

TEST(ClimbingStairsTest, Example1) {
    // Input: n = 2
    // Output: 2
    // Explanation: There are two ways to climb to the top.
    // 1. 1 step + 1 step
    // 2. 2 steps
    EXPECT_EQ(climbStairs(2), 2);
}

TEST(ClimbingStairsTest, Example2) {
    // Input: n = 3
    // Output: 3
    // Explanation: There are three ways to climb to the top.
    // 1. 1 step + 1 step + 1 step
    // 2. 1 step + 2 steps
    // 3. 2 steps + 1 step
    EXPECT_EQ(climbStairs(3), 3);
}

TEST(ClimbingStairsTest, SingleStep) {
    // Input: n = 1
    // Output: 1
    EXPECT_EQ(climbStairs(1), 1);
}

TEST(ClimbingStairsTest, FourSteps) {
    // Input: n = 4
    // Output: 5
    EXPECT_EQ(climbStairs(4), 5);
}

TEST(ClimbingStairsTest, FiveSteps) {
    // Input: n = 5
    // Output: 8
    EXPECT_EQ(climbStairs(5), 8);
}

TEST(ClimbingStairsTest, FourtyFiveSteps) {
    // Input: n = 5
    // Output: 8
    EXPECT_EQ(climbStairs(45), 8);
}
