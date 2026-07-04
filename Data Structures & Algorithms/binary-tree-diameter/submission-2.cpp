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
    int heightOfBinaryTree(TreeNode* root, int& diameter)
    {
        if(root == nullptr)
            return 0;

        int leftHeight = 1 + heightOfBinaryTree(root->left, diameter);
        int rightHeight = 1 + heightOfBinaryTree(root->right, diameter);

        diameter = max(diameter, rightHeight + leftHeight - 2);

        return max(leftHeight, rightHeight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        int h = heightOfBinaryTree(root, diameter);
        return diameter;
    }
};
