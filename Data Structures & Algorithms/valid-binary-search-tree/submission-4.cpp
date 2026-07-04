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
    // Time complexity: O(N), Space complexity: O(H)
    bool isValidBST(TreeNode* root)
    {
        stack<tuple<TreeNode*, long, long>> st;
        st.push({root, LONG_MIN, LONG_MAX});

        while(!st.empty())
        {
            auto [curr, minVal, maxVal] = st.top();
            st.pop();

            if (curr == nullptr)
                continue;

            if (minVal >= curr->val || maxVal <= curr->val)
                return false;

            st.push({curr->left, minVal, curr->val});
            st.push({curr->right, curr->val, maxVal});
        }

        return true;
    }
};
