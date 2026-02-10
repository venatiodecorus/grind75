/**
 * 383. Ransom Note
 * Difficulty: Easy
 * https://leetcode.com/problems/ransom-note
 * Given two strings ransomNote and magazine, return true if ransomNote can be
 * constructed by using the letters from magazine and false otherwise.
 * Each letter in magazine can only be used once in ransomNote.
 */

#include "383-ransom-note.h"
#include <map>

bool canConstruct(std::string ransomNote, std::string magazine) {
    // TODO: Implement solution
    std::map<char, int> ransomMap;
    std::map<char, int> magMap;

    // Naive approach, should fill one hashmap then empty it, failing if we go below 0.
    for(char c: ransomNote) {
        ransomMap[c] += 1;
    }

    for(char cc: magazine) {
        magMap[cc] += 1;
    }

    for(auto it: ransomMap) {
        if(magMap[it.first] < it.second) {
            return false;
        }
    }

    return true;
}
