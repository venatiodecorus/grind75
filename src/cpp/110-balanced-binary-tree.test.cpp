#include <gtest/gtest.h>
#include "110-balanced-binary-tree.h"

// Helper function to create tree from level-order array (with nullptr for null)
TreeNode* createTree(const std::vector<int*>& values, int index = 0) {
    if (index >= values.size() || values[index] == nullptr) {
        return nullptr;
    }
    
    TreeNode* root = new TreeNode(*values[index]);
    root->left = createTree(values, 2 * index + 1);
    root->right = createTree(values, 2 * index + 2);
    return root;
}

// Helper function to delete tree
void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

TEST(BalancedBinaryTreeTest, Example1) {
    // Input: root = [3,9,20,null,null,15,7]
    // Output: true
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    EXPECT_TRUE(isBalanced(root));
    
    deleteTree(root);
}

TEST(BalancedBinaryTreeTest, Example2) {
    // Input: root = [1,2,2,3,3,null,null,4,4]
    // Output: false
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->left->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(4);
    
    EXPECT_FALSE(isBalanced(root));
    
    deleteTree(root);
}

TEST(BalancedBinaryTreeTest, Example3) {
    // Input: root = []
    // Output: true
    TreeNode* root = nullptr;
    
    EXPECT_TRUE(isBalanced(root));
}
