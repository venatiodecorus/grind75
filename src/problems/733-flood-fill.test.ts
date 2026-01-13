import { floodFill } from "./733-flood-fill";

describe("Flood Fill", () => {
  test("Example 1: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2", () => {
    expect(floodFill([[1, 1, 1], [1, 1, 0], [1, 0, 1]], 1, 1, 2)).toEqual([
      [2, 2, 2],
      [2, 2, 0],
      [2, 0, 1],
    ]);
  });

  test("Example 2: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0", () => {
    expect(floodFill([[0, 0, 0], [0, 0, 0]], 0, 0, 0)).toEqual([
      [0, 0, 0],
      [0, 0, 0],
    ]);
  });
});
