#include <gtest/gtest.h>
#include "383-ransom-note.h"

TEST(RansomNoteTest, Example1) {
    // Input: ransomNote = "a", magazine = "b"
    // Output: false
    EXPECT_FALSE(canConstruct("a", "b"));
}

TEST(RansomNoteTest, Example2) {
    // Input: ransomNote = "aa", magazine = "ab"
    // Output: false
    EXPECT_FALSE(canConstruct("aa", "ab"));
}

TEST(RansomNoteTest, Example3) {
    // Input: ransomNote = "aa", magazine = "aab"
    // Output: true
    EXPECT_TRUE(canConstruct("aa", "aab"));
}
