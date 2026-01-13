import { isValid } from "./020-valid-parens";

describe("Valid Parentheses", () => {
  test("Example 1: (), true", () => {
    expect(isValid("()")).toEqual(true);
  });

  test("Example 2: ()[]{}, true", () => {
    expect(isValid("()[]{}")).toEqual(true);
  });

  test("Example 3: (], false", () => {
    expect(isValid("(]")).toEqual(false);
  });

  test("Example 4: ([]), true", () => {
    expect(isValid("([])")).toEqual(true);
  });

  test("Example 5: ([)], false", () => {
    expect(isValid("([)]")).toEqual(false);
  });

  test("Example 6: ], false", () => {
    expect(isValid("]")).toEqual(false);
  });
});
