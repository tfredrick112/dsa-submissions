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

/*
Time complexity - O(m*n) where m is the number of nodes in root and n is the number of nodes in subRoot
In the worst case, we call isSameTreeHelper for each of the m nodes in root; isSameTreeHelper is an O(n) function.
Space complexity - worst case O(m + n) - due to two recursion stacks, 1 for isSubTree and one for isSameTreeHelper.
*/
class Solution {
public:
    bool isSameTreeHelper(TreeNode* p, TreeNode* q)
    {
        if (p == nullptr && q == nullptr)
            return true;

        if (p == nullptr || q == nullptr)
            return false;

        if (p->val != q->val)
            return false;

        return isSameTreeHelper(p->left, q->left) && isSameTreeHelper(p->right, q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot)
    {
        bool isSameTree = isSameTreeHelper(root, subRoot);
        if (isSameTree)
            return true;

        if (root == nullptr)
            return false;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
