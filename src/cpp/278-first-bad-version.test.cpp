#include <gtest/gtest.h>
#include "278-first-bad-version.h"

// Global variable to control which version is the first bad one
static int g_badVersion = 0;

// Implementation of the isBadVersion API for testing
bool isBadVersion(int version) {
    return version >= g_badVersion;
}

TEST(FirstBadVersionTest, Example1) {
    // Input: n = 5, bad = 4
    // Output: 4
    g_badVersion = 4;
    EXPECT_EQ(firstBadVersion(5), 4);
}

TEST(FirstBadVersionTest, Example2) {
    // Input: n = 1, bad = 1
    // Output: 1
    g_badVersion = 1;
    EXPECT_EQ(firstBadVersion(1), 1);
}

TEST(FirstBadVersionTest, Example3) {
    // Input: n = 1, bad = 1
    // Output: 1
    g_badVersion = 2;
    EXPECT_EQ(firstBadVersion(2), 2);
}
