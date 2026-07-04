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
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        queue<TreeNode*> q1, q2;

        q1.push(p);
        q2.push(q);

        while(!q1.empty() && !q2.empty())
        {
            TreeNode* q1curr = q1.front();
            q1.pop();
            TreeNode* q2curr = q2.front();
            q2.pop();

            if (q1curr == nullptr && q2curr == nullptr)
            {
                continue;
            }

            if (q1curr == nullptr || q2curr == nullptr)
            {
                return false;
            }

            if (q1curr->val != q2curr->val)
            {
                return false;
            }

            q1.push(q1curr->left);
            q1.push(q1curr->right);

            q2.push(q2curr->left);
            q2.push(q2curr->right);
        }

        return true;
    }
};
