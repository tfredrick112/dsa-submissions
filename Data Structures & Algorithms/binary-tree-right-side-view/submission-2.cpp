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
    // Time complexity - O(N), Space complexity - O(H), H is the height of the binary tree.
    // H can be as high as N if the tree is skewed, for a balanced tree, H is close to log N
    void dfsHelper(TreeNode* root, int level, vector<int>& result)
    {
        if (root == nullptr)
            return;

        if (level >= result.size())
        {
            result.push_back(root->val);
        }

        dfsHelper(root->right, level + 1, result);
        dfsHelper(root->left, level + 1, result);
    }

    vector<int> rightSideView(TreeNode* root)
    {
        vector<int> result;
        dfsHelper(root, 0, result);
        return result;
    }
};
