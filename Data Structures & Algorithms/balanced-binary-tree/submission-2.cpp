/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxDepthHelper(TreeNode* root, bool& isBalancedTree)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int leftDepth = 1 + maxDepthHelper(root->left, isBalancedTree);
        int rightDepth = 1 + maxDepthHelper(root->right, isBalancedTree);

        if (abs(leftDepth - rightDepth) >= 2)
        {
            isBalancedTree = false;
        }

        return max(leftDepth, rightDepth);
    }
    bool isBalanced(TreeNode* root)
    {
        bool isBalancedTree = true;
        int h = maxDepthHelper(root, isBalancedTree);
        return isBalancedTree;
    }
};
