import { search } from "./704-binary-search";

describe("Binary Search", () => {
  test("Example 1: nums = [-1,0,3,5,9,12], target = 9", () => {
    expect(search([-1, 0, 3, 5, 9, 12], 9)).toBe(4);
  });

  test("Example 2: nums = [-1,0,3,5,9,12], target = 2", () => {
    expect(search([-1, 0, 3, 5, 9, 12], 2)).toBe(-1);
  });
});
