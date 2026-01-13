/**
 * 20. Valid Parentheses
 * Difficulty: Easy
 * https://leetcode.com/problems/valid-parentheses
 *
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
 * determine if the input string is valid.
 *
 * An input string is valid if:
 * - Open brackets must be closed by the same type of brackets.
 * - Open brackets must be closed in the correct order.
 * - Every close bracket has a corresponding open bracket of the same type.
 */

export function isValid(s: string): boolean {
  let stack: string[] = [];
  let open = "([{";
  for (let c of s) {
    if (open.includes(c)) {
      stack.push(c);
    } else {
      if (
        (c == ")" && stack.at(-1) == "(") ||
        (c == "]" && stack.at(-1) == "[") ||
        (c == "}" && stack.at(-1) == "{")
      ) {
        stack.pop();
      } else {
        stack.push(c);
      }
    }
  }
  return stack.length == 0;
}
