class TrieNode {
    public:
        bool isLeaf;
        int childrenCount;
        int wordIndex;
        TrieNode* children[26];

        TrieNode()
        {
            isLeaf = false;
            wordIndex = -2;
            childrenCount = 0;
            for (int i = 0; i < 26; i++)
            {
                children[i] = nullptr;
            }
        }

        ~TrieNode()
        {
            for (int i = 0; i < 26; i++)
            {
                delete children[i];
                children[i] = nullptr;
            }
        }
};
class Trie {
    public:
        TrieNode* root = nullptr;
        Trie()
        {
            root = new TrieNode();
        }

        void insert(string& word, int index)
        {
            TrieNode* curr = root;

            for (char ch : word)
            {
                if (curr->children[ch - 'a'] == nullptr)
                {
                    TrieNode* newNode = new TrieNode();
                    curr->children[ch - 'a'] = newNode;
                    curr->childrenCount++;
                    curr = newNode;
                }
                else
                {
                    curr = curr->children[ch - 'a'];
                }
            }

            curr->isLeaf = true;
            curr->wordIndex = index;
        }

        ~Trie()
        {
            delete root;
            root = nullptr;
        }
};
class Solution {
public:
    vector<vector<int>> directions = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}
    };
    void addWordsToTrie(vector<string>& words, Trie* trie)
    {
        for (int i = 0; i < words.size(); i++)
        {
            trie->insert(words[i], i);
        }
    }

    bool backtrack(vector<vector<char>>& board, TrieNode* curr, vector<vector<bool>>& visited, int x, int y, int m, int n, vector<int>& result)
    {
        if (curr->isLeaf && curr->wordIndex >= 0)
        {
            result.push_back(curr->wordIndex);
            curr->wordIndex = -1; // so that we do not find the same word again
        }

        for (const auto& d: directions)
        {
            int x_new = x + d[0], y_new = y + d[1];
            if (x_new >= 0 && x_new < m && y_new >= 0 && y_new < n && !visited[x_new][y_new])
            {
                char nextCh = board[x_new][y_new];
                if (curr->children[nextCh - 'a'] != nullptr)
                {
                    visited[x_new][y_new] = true;
                    bool deletePtr = backtrack(board, curr->children[nextCh - 'a'], visited, x_new, y_new, m, n, result);
                    if (deletePtr)
                    {
                        curr->children[nextCh - 'a'] = nullptr;
                        curr->childrenCount--;
                    }

                    visited[x_new][y_new] = false;
                }
            }
        }

        if (curr->childrenCount == 0)
        {
            delete curr;
            return true;
        }
        else
        {
            return false;
        }
    }

    // Time complexity - O(mn * 3 ^ L). There are mn starting points for the search
    // for each cell there are 3 possible routes (not 4, as you cannot go back to the cell you came from)
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        Trie* trie = new Trie();
        addWordsToTrie(words, trie);

        TrieNode* root = trie->root;
        int m = board.size(), n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        vector<int> resultIndices;
        vector<string> result;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                char ch = board[i][j];
                if (root->children[ch - 'a'] != nullptr)
                {
                    visited[i][j] = true;
                    bool deletePtr = backtrack(board, root->children[ch - 'a'], visited, i, j, m, n, resultIndices);
                    if (deletePtr)
                    {
                        root->children[ch - 'a'] = nullptr;
                        root->childrenCount--;
                    }
                    visited[i][j] = false;
                }
            }
        }

        for (int index : resultIndices)
        {
            result.push_back(words[index]);
        }

        delete trie;
        trie = nullptr;

        return result;
    }
};
