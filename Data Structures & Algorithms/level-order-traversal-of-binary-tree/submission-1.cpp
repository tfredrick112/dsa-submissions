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
    // Time - O(N)
    // Space - O(H) for the recursion stack (H can be N for a skewed tree and log N for a balanced tree)
    // output space - O(N)
    void levelOrderHelper(TreeNode* root, int level, vector<vector<int>>& res)
    {
        if (root==nullptr)
            return;

        if(res.size()<=level)
            res.push_back({});

        res[level].push_back(root->val);

        levelOrderHelper(root->left, level + 1, res);
        levelOrderHelper(root->right, level + 1, res);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        levelOrderHelper(root, 0, res);
        return res;
    }
};
