import { isPalindrome } from "./125-valid-palindrome";

describe("Valid Palindrome", () => {
  test('Example 1: s = "A man, a plan, a canal: Panama"', () => {
    expect(isPalindrome("A man, a plan, a canal: Panama")).toBe(true);
  });

  test('Example 2: s = "race a car"', () => {
    expect(isPalindrome("race a car")).toBe(false);
  });

  test('Example 3: s = " "', () => {
    expect(isPalindrome(" ")).toBe(true);
  });
});
