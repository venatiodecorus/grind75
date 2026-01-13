/**
 * 125. Valid Palindrome
 * Difficulty: Easy
 * https://leetcode.com/problems/valid-palindrome
 * A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
 * Given a string s, return true if it is a palindrome, or false otherwise.
 */

export function isPalindrome(s: string): boolean {
  const cleaned = s.toLowerCase().replace(/[^a-z0-9]/g, "");

  for (let i = 0; i <= cleaned.length / 2; i++) {
    if (cleaned[i] != cleaned[cleaned.length - 1 - i]) return false;
  }
  return true;
}
