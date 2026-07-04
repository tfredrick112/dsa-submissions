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
    // Space - O(W) where W is the maximum number of nodes in a level (it can be as high as N/2)
    // output space - O(N)
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> result;

        if (root == nullptr)
            return result;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int currSize = q.size();
            vector<int> currLevel;
            for (int i = 0; i < currSize; i++)
            {
                TreeNode* curr = q.front();
                q.pop();

                currLevel.push_back(curr->val);

                if (curr->left != nullptr)
                    q.push(curr->left);

                if (curr->right != nullptr)
                    q.push(curr->right);
            }

            result.push_back(currLevel);
        }

        return result;
    }
};
