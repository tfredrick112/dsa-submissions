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
    // Time complexity - O(N) ; space complexity - O(N)
    TreeNode* buildTreeHelper(vector<int>& preorder, int pStart, int pEnd, vector<int>& inorder, int iStart, int iEnd, unordered_map<int,int>& hashMap)
    {
        if (pStart > pEnd)
            return nullptr;
        
        int rootValue = preorder[pStart];
        int index = hashMap[rootValue];

        int leftCount = index - iStart;
        int rightCount = iEnd - index;

        TreeNode* node = new TreeNode(rootValue);

        if (leftCount > 0)
            node->left = buildTreeHelper(preorder, pStart + 1, pStart + leftCount, inorder, iStart, index - 1, hashMap);

        if (rightCount > 0)
            node->right = buildTreeHelper(preorder, pStart + leftCount + 1, pEnd, inorder, index + 1, iEnd, hashMap);

        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        int n = preorder.size();

        unordered_map<int, int> hashMap;

        for (int i = 0; i < n; i++)
        {
            hashMap[inorder[i]] = i;
        }

        return buildTreeHelper(preorder, 0, n - 1, inorder, 0, n - 1, hashMap);
    }
};
