/**
 * 110. Balanced Binary Tree
 * Difficulty: Easy
 * https://leetcode.com/problems/balanced-binary-tree
 * Given a binary tree, determine if it is height-balanced.
 */

#include "110-balanced-binary-tree.h"
#include <algorithm>

int depth(TreeNode* node) {
    if(!node) return 0;
    int max = std::max(depth(node->left), depth(node->right));
    return max+1;
}

bool isBalanced(TreeNode* root) {
    // TODO: Implement solution
    if(!root) return true;

    int diff = std::abs(depth(root->left) - depth(root->right));
    if(diff <= 1 && isBalanced(root->left) && isBalanced(root->right)) return true;

    return false;
}
