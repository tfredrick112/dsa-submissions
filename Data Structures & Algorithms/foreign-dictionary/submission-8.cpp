class Solution {
public:
    // // Time complexity -> Collection of characters: O(n * L)
    // // Graph creation after comparing adjacent words: O(n * L)
    // // dfs: O(V + E) <= O(V + V^2); Clearly, V is at most 26.
    // // Space complexity - O(1) — all structures bounded by alphabet size 26.
    // bool dfs(unordered_map<char, unordered_set<char>>& adj, char src, vector<bool>& visited, vector<bool>& currPath, string& result)
    // {
    //     if (currPath[src - 'a'])
    //         return true;

    //     if (visited[src - 'a'])
    //         return false;

    //     visited[src - 'a'] = true;
    //     currPath[src - 'a'] = true;

    //     for (char nei : adj[src])
    //     {
    //         if (currPath[nei - 'a'])
    //             return true;

    //         if (!visited[nei - 'a'])
    //         {
    //             bool isCycleFound = dfs(adj, nei, visited, currPath, result);
    //             if (isCycleFound)
    //                 return true;
    //         }
    //     }

    //     result += src;
    //     currPath[src - 'a'] = false;
    //     return false;
    // }

    // string foreignDictionary(vector<string>& words)
    // {
    //     unordered_map<char, unordered_set<char>> adj;

    //     unordered_set<char> allChars;

    //     int n = words.size();

    //     for (int i = 0; i < n; i++)
    //     {
    //         for (int j = 0; j < words[i].size(); j++)
    //         {
    //             allChars.insert(words[i][j]);
    //         }
    //     }

    //     for (int i = 0; i < n - 1; i++)
    //     {
    //         int j = i + 1;
    //         string w1 = words[i], w2 = words[j];
    //         int len1 = w1.size(), len2 = w2.size();

    //         int k = 0;
    //         while (k < len1 && k < len2)
    //         {
    //             if (w1[k] == w2[k])
    //             {
    //                 k++;
    //                 continue;
    //             }

    //             // put a directed edge from w1[k] to w2[k]
    //             adj[w1[k]].insert(w2[k]);
    //             break;
    //         }

    //         if (k == len2 && k < len1)
    //         {
    //             return "";
    //         }
    //     }

    //     vector<bool> visited(26, false);
    //     vector<bool> currPath(26, false);

    //     string result = "";

    //     for (char ch : allChars)
    //     {
    //         if (!visited[ch - 'a'])
    //         {
    //             bool isCycleFound = dfs(adj, ch, visited, currPath, result);
    //             if (isCycleFound)
    //                 return "";
    //         }
    //     }

    //     reverse(result.begin(), result.end());

    //     return result;
    // }

    // Using Kahn's topological sorting algorithm
    bool addEdgeBasedOnWordComparison(string& word1, string& word2, unordered_map<char, unordered_set<char>>& adj)
    {
        int m = word1.size(), n = word2.size(), i = 0, j = 0;
        while(i < m && j < n && word1[i] == word2[j])
        {
            i++;
            j++;
        }
        
        if (i < m && j >= n)
        {
            return false;
        }
        
        if (i < m && j < n)
        {
            adj[word1[i]].insert(word2[j]);
        }
        
        return true;
    }
    string foreignDictionary(vector<string>& words) {
        // code here
        unordered_map<char, unordered_set<char>> adj;
        int n = words.size();
        
        for (int i = 0; i < n - 1; i++)
        {
            int j = i + 1;
            bool res = addEdgeBasedOnWordComparison(words[i], words[j], adj);
            if (!res)
                return "";
        }
        
        // this set should contain all the unique characters in the given words
        unordered_set<char> allChars;
        for (int i = 0; i < n; i++)
        {
            for (char ch : words[i])
            {
                allChars.insert(ch);
            }
        }
        
        // indegree of each node
        int indegree[26];
        fill(indegree, indegree + 26, 0);
        for (const auto& [k, v] : adj)
        {
            for (char ch : v)
            {
                indegree[ch - 'a']++;
            }
        }
        
        queue<char> q;
        string result = "";
        
        // start by pushing every node with indegree 0 into the queue
        for (char ch : allChars)
        {
            if (indegree[ch - 'a'] == 0)
            {
                q.push(ch);
            }
        }
        
        while(!q.empty())
        {
            char curr = q.front();
            q.pop();
            
            result += curr;
            
            for(char nei : adj[curr])
            {
                indegree[nei - 'a']--;
                if (indegree[nei - 'a'] == 0)
                    q.push(nei);
            }
        }
        
        if (result.size() == allChars.size())
        {
            return result;
        }
        else
        {
            return "";
        }
    }
};

