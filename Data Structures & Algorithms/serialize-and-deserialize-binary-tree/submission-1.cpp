/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        vector<string> result;
        serializeHelper(root, result);

        ostringstream oss;
        for (const auto& s : result)
        {
            oss << s << ",";
        }

        string resultStr = oss.str();
        resultStr.pop_back();
        return resultStr;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        vector<string> tokens;
        splitString(data, ",", tokens);

        int i = 0;
        return deserializeHelper(tokens, i);
    }

private:
    void splitString(string& input, string delimiter, vector<string>& tokens)
    {
        int start = 0;
        int end = input.find(delimiter);

        while (end != string::npos)
        {
            tokens.push_back(input.substr(start, end - start));
            start = end + delimiter.size();
            end = input.find(delimiter, start);
        }

        tokens.push_back(input.substr(start));
    }

    void serializeHelper(TreeNode* root, vector<string>& result)
    {
        if (root == nullptr)
        {
            result.push_back("N");
            return;
        }

        result.push_back(to_string(root->val));
        serializeHelper(root->left, result);
        serializeHelper(root->right, result);
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
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));