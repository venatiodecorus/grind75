/**
 * 242. Valid Anagram
 * Difficulty: Easy
 * https://leetcode.com/problems/valid-anagram
 * Given two strings s and t, return true if t is an anagram of s, and false otherwise.
 */

export function isAnagram(s: string, t: string): boolean {
  if (s.length != t.length) return false;

  let arr: { [key: string]: number } = {};
  for (let x = 0; x < s.length; x++) {
    arr[s[x]] = (arr[s[x]] || 0) + 1;
    arr[t[x]] = (arr[t[x]] || 0) - 1;
  }

  for (let n in arr) {
    if (arr[n] != 0) return false;
  }

  return true;
}
