class Solution {
public:
    // Time complexity: O(n^2 * L) where n is the number of words in wordList and L is the length of each word.
    // O(n^2 * L) time taken to build the adjacency list and O(n^2) for BFS.

    int BFS(unordered_map<string, vector<string>>& adj, string src, string endWord)
    {
        unordered_set<string> visited;
        queue<string> q;

        q.push(src);
        visited.insert(src);

        int level = 1;

        while(!q.empty())
        {
            int currSize = q.size();
            for(int i = 0; i < currSize; i++)
            {
                string curr = q.front();
                q.pop();

                if (curr == endWord)
                {
                    return level;
                }

                for (string& nei : adj[curr])
                {
                    if (visited.count(nei) == 0)
                    {
                        q.push(nei);
                        visited.insert(nei);
                    }
                }
            }

            level++;
        }

        return 0;
    }
    void compareWords(string& w1, string& w2, unordered_map<string, vector<string>>& adj)
    {
        int k = 0, diff = 0;
        while (k < w1.size())
        {
            if (w1[k] != w2[k])
            {
                diff++;
            }

            k++;
        }

        if (diff == 1)
        {
            adj[w1].push_back(w2);
            adj[w2].push_back(w1);
        }
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        int n = wordList.size();

        bool found = false;
        for (int i = 0; i < n; i++)
        {
            if (endWord == wordList[i])
            {
                found = true;
                break;
            }
        }

        if (!found)
            return 0;

        unordered_map<string, vector<string>> adj;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                compareWords(wordList[i], wordList[j], adj);
            }
        }

        for (int i = 0; i < n; i++)
        {
            compareWords(beginWord, wordList[i], adj);
        }

        return BFS(adj, beginWord, endWord);
    }
};
