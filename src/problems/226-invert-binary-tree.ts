/**
 * 226. Invert Binary Tree
 * Difficulty: Easy
 * https://leetcode.com/problems/invert-binary-tree
 * Given the root of a binary tree, invert the tree, and return its root.
 */

export class TreeNode {
  val: number;
  left: TreeNode | null;
  right: TreeNode | null;
  constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
  }
}

export function invertTree(root: TreeNode | null): TreeNode | null {
  if (!root) return null;
  if (root.left == null && root.right == null) return root;
  let oldLeft = root.left;
  let oldRight = root.right;
  root.left = invertTree(oldRight);
  root.right = invertTree(oldLeft);
  return root;
}
