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
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> result;
        if (root == nullptr)
            return result;

        stack<TreeNode*> st;
        TreeNode* curr = root;
        TreeNode* lastVisited = nullptr;

        while(curr != nullptr || !st.empty())
        {
            while(curr != nullptr)
            {
                st.push(curr);
                curr = curr->left;
            }

            TreeNode* peekNode = st.top();

            if (peekNode->right != nullptr && peekNode->right != lastVisited)
            {
                curr = peekNode->right;
            }
            else
            {
                st.pop();
                result.push_back(peekNode->val);
                lastVisited = peekNode;
            }
        }

        return result;
    }
};