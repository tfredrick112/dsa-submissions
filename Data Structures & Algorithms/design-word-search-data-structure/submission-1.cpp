class TrieNode {
    public:
        bool isLeaf = false;
        TrieNode* children[26];

        TrieNode()
        {
            isLeaf = false;
            for (int i = 0; i < 26; i++)
            {
                children[i] = nullptr;
            }
        }
};
class WordDictionary {
public:
    TrieNode* root = nullptr;
    WordDictionary() {
        root = new TrieNode();
    }
    
    // time: O(L) where L is the length of the word
    // space: O(26L), in the worst case, we add L new nodes to the trie and each node has an array of size 26
    void addWord(string word)
    {
        TrieNode* curr = root;

        for (char ch : word)
        {
            if (curr->children[ch - 'a'] == nullptr)
            {
                TrieNode* newNode = new TrieNode();
                curr->children[ch - 'a'] = newNode;
                curr = curr->children[ch - 'a'];
            }
            else
            {
                curr = curr->children[ch - 'a'];
            }
        }

        curr->isLeaf = true;
    }
    
    // time: O(26^d . L), where d is the number of dots. When we have a dot, we end up exploring 26 branches
    // space: O(L) recursion stack
    bool search(string word)
    {
        return searchHelper(word, 0, root);
    }

    private:
    bool searchHelper(string& word, int i, TrieNode* curr)
    {
        if (i == word.size())
        {
            return curr->isLeaf;
        }

        char ch = word[i];

        if (ch == '.')
        {
            bool result = false;

            for (int j = 0; j < 26; j++)
            {
                if (curr->children[j] != nullptr)
                {
                    result = result || searchHelper(word, i + 1, curr->children[j]);
                }
            }

            return result;
        }
        else
        {
            if (curr->children[ch - 'a'] != nullptr)
            {
                return searchHelper(word, i + 1, curr->children[ch - 'a']);
            }
            else
            {
                return false;
            }
        }
    }
};
