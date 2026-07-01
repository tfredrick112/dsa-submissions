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

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        if (root == nullptr)
        {
            return "N";
        }

        string result = to_string(root->val);

        result = result + "," + serialize(root->left);
        result = result + "," + serialize(root->right);

        return result;
    }

    vector<string> splitString(string& input, string delimiter)
    {
        vector<string> tokens;

        size_t start = 0;
        size_t end = input.find(delimiter);

        while (end != string::npos)
        {
            tokens.push_back(input.substr(start, end - start));
            start = end + delimiter.size();
            end = input.find(delimiter, start);
        }

        tokens.push_back(input.substr(start));
        return tokens;
    }

    TreeNode* deserializeHelper(vector<string>& v, int& i)
    {
        if (v[i] == "N")
        {
            i++;
            return nullptr;
        }

        TreeNode* newNode = new TreeNode(stoi(v[i]));
        i++;

        newNode->left = deserializeHelper(v, i);
        newNode->right = deserializeHelper(v, i);

        return newNode;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        if (data == "N")
            return nullptr;

        vector<string> v = splitString(data, ",");
        int i = 0;
        return deserializeHelper(v, i);
    }
};
