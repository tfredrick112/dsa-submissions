class Solution {
public:
    // Time complexity -> Collection of characters: O(n * L)
    // Graph creation after comparing adjacent words: O(n * L)
    // dfs: O(V + E) <= O(V + V^2); Clearly, V is at most 26.
    // Space complexity - O(1) — all structures bounded by alphabet size 26.
    bool dfs(unordered_map<char, unordered_set<char>>& adj, char src, vector<bool>& visited, vector<bool>& currPath, string& result)
    {
        if (currPath[src - 'a'])
            return true;

        if (visited[src - 'a'])
            return false;

        visited[src - 'a'] = true;
        currPath[src - 'a'] = true;

        for (char nei : adj[src])
        {
            if (currPath[nei - 'a'])
                return true;

            if (!visited[nei - 'a'])
            {
                bool isCycleFound = dfs(adj, nei, visited, currPath, result);
                if (isCycleFound)
                    return true;
            }
        }

        result += src;
        currPath[src - 'a'] = false;
        return false;
    }

    string foreignDictionary(vector<string>& words)
    {
        unordered_map<char, unordered_set<char>> adj;

        unordered_set<char> allChars;

        int n = words.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < words[i].size(); j++)
            {
                allChars.insert(words[i][j]);
            }
        }

        for (int i = 0; i < n - 1; i++)
        {
            int j = i + 1;
            string w1 = words[i], w2 = words[j];
            int len1 = w1.size(), len2 = w2.size();

            int k = 0;
            while (k < len1 && k < len2)
            {
                if (w1[k] == w2[k])
                {
                    k++;
                    continue;
                }

                // put a directed edge from w1[k] to w2[k]
                adj[w1[k]].insert(w2[k]);
                break;
            }

            if (k == len2 && k < len1)
            {
                return "";
            }
        }

        vector<bool> visited(26, false);
        vector<bool> currPath(26, false);

        string result = "";

        for (char ch : allChars)
        {
            if (!visited[ch - 'a'])
            {
                bool isCycleFound = dfs(adj, ch, visited, currPath, result);
                if (isCycleFound)
                    return "";
            }
        }

        reverse(result.begin(), result.end());

        return result;
    }
};
