#include <gtest/gtest.h>
#include "409-longest-palindrome.h"

TEST(LongestPalindromeTest, Example1) {
    // Input: s = "abccccdd"
    // Output: 7
    // Explanation: One longest palindrome that can be built is "dccaccd",
    // whose length is 7.
    EXPECT_EQ(longestPalindrome("abccccdd"), 7);
}

TEST(LongestPalindromeTest, Example2) {
    // Input: s = "a"
    // Output: 1
    // Explanation: The longest palindrome that can be built is "a",
    // whose length is 1.
    EXPECT_EQ(longestPalindrome("a"), 1);
}

TEST(LongestPalindromeTest, AllSameCharacters) {
    // Input: s = "aaaa"
    // Output: 4
    EXPECT_EQ(longestPalindrome("aaaa"), 4);
}

TEST(LongestPalindromeTest, CaseSensitive) {
    // Input: s = "Aa"
    // Output: 1
    // "Aa" is not a palindrome since it is case sensitive.
    EXPECT_EQ(longestPalindrome("Aa"), 1);
}

TEST(LongestPalindromeTest, AllUnique) {
    // Input: s = "abcdef"
    // Output: 1
    EXPECT_EQ(longestPalindrome("abcdef"), 1);
}
