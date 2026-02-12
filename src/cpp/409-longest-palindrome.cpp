/**
 * 409. Longest Palindrome
 * Difficulty: Easy
 * https://leetcode.com/problems/longest-palindrome
 * Given a string s which consists of lowercase or uppercase letters,
 * return the length of the longest palindrome that can be built with
 * those letters. Letters are case sensitive.
 */

#include "409-longest-palindrome.h"
#include <unordered_map>

int longestPalindrome(std::string s) {
    std::unordered_map<char, int> freq;
    int len = 0;
    for(char c: s) {
        freq[c]++;
        if(freq[c] / 2 > 0) {
            len += 2;
            freq[c] = 0;
        }
    }

    if(len < s.length()) {
        len++;
    }

    return len;

    // FIRST ATTEMPT
    // std::unordered_map<char, int> freq;
    // int len = 0;
    // for(char c: s) {
    //     freq[c]++;
    // }

    // bool hasOne = false;
    // for(auto& [key,value] : freq) {
    //     if(value / 2 > 0) {
    //         len += value;
    //     }
    //     if(value == 1) {
    //         hasOne = true;
    //     }
    // }

    // if(hasOne) len++;

    // return len;
}
