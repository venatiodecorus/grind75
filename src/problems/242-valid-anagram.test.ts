import { isAnagram } from "./242-valid-anagram";

describe("Valid Anagram", () => {
  test('Example 1: s = "anagram", t = "nagaram"', () => {
    expect(isAnagram("anagram", "nagaram")).toBe(true);
  });

  test('Example 2: s = "rat", t = "car"', () => {
    expect(isAnagram("rat", "car")).toBe(false);
  });

  test('Example 3: s = "aa", t = "bb"', () => {
    expect(isAnagram("aa", "bb")).toBe(false);
  });
});
