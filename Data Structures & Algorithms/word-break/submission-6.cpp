struct Node{
    bool isLeaf;
    Node* neighbors[26];
    Node()
    {
        isLeaf = false;
        fill(neighbors, neighbors + 26, nullptr);
    }
};
class PrefixTree {
    public:
        Node *root;
        PrefixTree()
        {
            root = new Node();
        }

        void addWord(const string& word)
        {
            Node *curr = root;
            int n = word.size();

            for (int i = 0; i < n; i++)
            {
                char ch = word[i];
                if (curr->neighbors[ch - 'a'] != nullptr)
                {
                    curr = curr->neighbors[ch - 'a'];
                }
                else
                {
                    Node *newNode = new Node();
                    curr->neighbors[ch - 'a'] = newNode;
                    curr = newNode;
                }
            }

            curr->isLeaf = true;
        }
};
class Solution {
public:
    // Time complexity = O(n * maxLen) for the DP-trie walk and O(sum of dict word lengths) for trie creation
    // Space complexity = O(n) for dp + O((sum of word lengths) * 26) for trie
    bool wordBreak(string s, vector<string>& wordDict)
    {
        int n = s.size();

        vector<bool> dp(n + 1, false);
        // dp[i] = true if the s[i to n - 1] can be broken into dictionary words

        dp[n] = true;

        PrefixTree *obj = new PrefixTree();
        int maxLen = 0;
        for (const auto& word : wordDict)
        {
            maxLen = max(maxLen, (int)word.size());
            obj->addWord(word);
        }

        for (int i = n - 1; i >= 0; i--)
        {
            Node *curr = obj->root;
            for (int len = 1; len <= maxLen; len++)
            {
                int j = len + i - 1;
                if (j >= n)
                    break;

                if (curr->neighbors[s[j] - 'a'] != nullptr)
                {
                    curr = curr->neighbors[s[j] - 'a'];
                }
                else
                {
                    break;
                }

                
                if (curr->isLeaf && dp[j + 1])
                {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[0];
    }
};
