class Solution {
public:
    /*
    My explanation:

I am starting a breadth first search traversal from "beginWord". beginWord and each word in  wordList form the nodes of my graph. Starting from "beginWord", I try to find the shortest path to endWord. BFS is guaranteed to return the shortest path because all nodes at level k are explored before nodes at level k + 1.

Instead of precomputing the neighbours by doing a pairwise comparison of all words in wordList, I generate and check for neighbours on the fly, during BFS. For each node popped out of the queue, I vary one character at a time and check if it occurs in wordList. If yes, then it is a valid neighbour. if that neighbour is not yet visited, then it is pushed into the queue and marked as visited.

Time complexity:

In BFS, at most "n" words (nodes) get pushed into and popped out of the queue. Generating neighbours for each word is the bottle neck. If the length of each word is L, then I am trying out 26 * L possibilities for each work. If it takes O(L) time to create each new potential neighbour, then total time taken for BFS is O(n * 26 * L * L).
    */
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        queue<string> q;
        unordered_set<string> visited;

        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        if (wordSet.count(endWord) == 0)
            return 0; // not possible to reach endWord if it does not exist in the given list

        q.push(beginWord);
        visited.insert(beginWord);

        int level = 1;

        while(!q.empty())
        {
            int currSize = q.size();
            for (int i = 0; i < currSize; i++)
            {
                string curr = q.front();
                q.pop();

                if (curr == endWord)
                    return level;

                // generate neighbours
                for (int i = 0; i < curr.size(); i++)
                {
                    string nei = curr;

                    // char originalChar = curr[i];
                    for (int j = 97; j <= 122; j++)
                    {
                        char newChar = (char)j;
                        // if (newChar == originalChar)
                        //     continue;

                        nei[i] = newChar;

                        if (wordSet.count(nei) > 0 && visited.count(nei) == 0)
                        {
                            q.push(nei);
                            visited.insert(nei);
                        }
                    }
                }
            }

            level++;
        }

        return 0;
    }
};
