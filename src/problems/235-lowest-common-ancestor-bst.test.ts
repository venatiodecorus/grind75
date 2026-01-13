import {
  lowestCommonAncestor,
  TreeNode,
} from "./235-lowest-common-ancestor-bst";

// Helper function to build tree from array
function buildTree(arr: (number | null)[]): TreeNode | null {
  if (!arr.length || arr[0] === null) return null;

  const root = new TreeNode(arr[0]);
  const queue: TreeNode[] = [root];
  let i = 1;

  while (queue.length && i < arr.length) {
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

// Helper function to find node by value
function findNode(root: TreeNode | null, val: number): TreeNode | null {
  if (!root) return null;
  if (root.val === val) return root;

  const left = findNode(root.left, val);
  if (left) return left;

  return findNode(root.right, val);
}

describe("Lowest Common Ancestor of a Binary Search Tree", () => {
  test("Example 1: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8", () => {
    const root = buildTree([6, 2, 8, 0, 4, 7, 9, null, null, 3, 5]);
    const p = findNode(root, 2);
    const q = findNode(root, 8);
    const result = lowestCommonAncestor(root, p, q);
    expect(result?.val).toBe(6);
  });

  test("Example 2: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4", () => {
    const root = buildTree([6, 2, 8, 0, 4, 7, 9, null, null, 3, 5]);
    const p = findNode(root, 2);
    const q = findNode(root, 4);
    const result = lowestCommonAncestor(root, p, q);
    expect(result?.val).toBe(2);
  });

  test("Example 3: root = [2,1], p = 2, q = 1", () => {
    const root = buildTree([2, 1]);
    const p = findNode(root, 2);
    const q = findNode(root, 1);
    const result = lowestCommonAncestor(root, p, q);
    expect(result?.val).toBe(2);
  });
});
