/**
 * 733. Flood Fill
 * Difficulty: Easy
 * https://leetcode.com/problems/flood-fill
 * You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image.
 * You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].
 *
 * To perform a flood fill:
 * 1. Begin with the starting pixel and change its color to color.
 * 2. Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
 * 3. Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
 * 4. The process stops when there are no more adjacent pixels of the original color to update.
 *
 * Return the modified image after performing the flood fill.
 */

export function floodFill(
  image: number[][],
  sr: number,
  sc: number,
  color: number,
): number[][] {
  const origColor = image[sr][sc];

  if (origColor === color) {
    return image;
  }

  image[sr][sc] = color;

  const directions = [
    [0, 1],
    [0, -1],
    [1, 0],
    [-1, 0],
  ];

  for (const [dr, dc] of directions) {
    const newRow = sr + dr;
    const newCol = sc + dc;

    if (
      newRow >= 0 &&
      newRow < image.length &&
      newCol >= 0 &&
      newCol < image[0].length
    ) {
      // access image[newRow][newCol]
      if (image[newRow][newCol] == origColor) {
        image = floodFill(image, newRow, newCol, color);
      }
    }
  }

  return image;
}
