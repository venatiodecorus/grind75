/**
 * 70. Climbing Stairs
 * Difficulty: Easy
 * https://leetcode.com/problems/climbing-stairs
 * You are climbing a staircase. It takes n steps to reach the top.
 * Each time you can either climb 1 or 2 steps. In how many distinct
 * ways can you climb to the top?
 */

#include "70-climbing-stairs.h"
#include <unordered_map>


int calc(int n, std::unordered_map<int, int>& memo) {
    if( n == 1) return 1;
    if( n == 2) return 2;
    if(memo.count(n)) return memo[n];
    memo[n] = calc(n-1, memo) + calc(n-2, memo);
    return memo[n];
}

int climbStairs(int n) {
    std::unordered_map<int, int> memo;
    return calc(n, memo);
}


// int calc(int n) {
//     if(n == 1) return 1;
//     if(n == 2) return 2;
//     return calc(n-1) + calc(n-2);
// }

// int climbStairs(int n) {
//     // TODO: Implement solution
//     bool ready[n];
//     int value[n];

//     if(ready[n]) return value[n];
//     value[n] = calc(n);
//     ready[n] = true;
// }
