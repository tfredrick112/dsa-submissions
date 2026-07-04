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
    // Time complexity - O(N), Space complexity - O(W), W being the maximum width or maximum
    // number of nodes in one level. W can be as high as N/2.
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr)
            return {};

        vector<int> result;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int len = q.size();

            // Pop out all but the last node of the current level
            for (int i = 0; i < len; i++)
            {
                TreeNode* curr = q.front();
                q.pop();

                if (curr->left != nullptr)
                    q.push(curr->left);

                if (curr->right != nullptr)
                    q.push(curr->right);

                if (i == len - 1)
                    result.push_back(curr->val);
            }
        }

        return result;
    }
};
