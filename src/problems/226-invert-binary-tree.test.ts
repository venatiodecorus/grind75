import { invertTree, TreeNode } from "./226-invert-binary-tree";

// Helper function to convert array to binary tree (level-order)
function arrayToTree(arr: (number | null)[]): TreeNode | null {
  if (arr.length === 0 || arr[0] === null) return null;

  const root = new TreeNode(arr[0]);
  const queue: TreeNode[] = [root];
  let i = 1;

  while (queue.length > 0 && i < arr.length) {
    const node = queue.shift()!;

    if (i < arr.length && arr[i] !== null) {
      node.left = new TreeNode(arr[i]!);
      queue.push(node.left);
    }
    i++;

    if (i < arr.length && arr[i] !== null) {
      node.right = new TreeNode(arr[i]!);
      queue.push(node.right);
    }
    i++;
  }

  return root;
}

// Helper function to convert binary tree to array (level-order)
function treeToArray(root: TreeNode | null): (number | null)[] {
  if (!root) return [];

  const result: (number | null)[] = [];
  const queue: (TreeNode | null)[] = [root];

  while (queue.length > 0) {
    const node = queue.shift()!;

    if (node === null) {
      result.push(null);
    } else {
      result.push(node.val);
      queue.push(node.left);
      queue.push(node.right);
    }
  }

  // Remove trailing nulls
  while (result.length > 0 && result[result.length - 1] === null) {
    result.pop();
  }

  return result;
}

describe("Invert Binary Tree", () => {
  test("Example 1: root = [4,2,7,1,3,6,9]", () => {
    const root = arrayToTree([4, 2, 7, 1, 3, 6, 9]);
    const inverted = invertTree(root);
    expect(treeToArray(inverted)).toEqual([4, 7, 2, 9, 6, 3, 1]);
  });

  test("Example 2: root = [2,1,3]", () => {
    const root = arrayToTree([2, 1, 3]);
    const inverted = invertTree(root);
    expect(treeToArray(inverted)).toEqual([2, 3, 1]);
  });

  test("Example 3: root = []", () => {
    const root = arrayToTree([]);
    const inverted = invertTree(root);
    expect(treeToArray(inverted)).toEqual([]);
  });
});
