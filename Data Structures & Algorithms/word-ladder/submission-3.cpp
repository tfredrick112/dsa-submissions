class Solution {
public:
    /*
    My explanation:

I am starting a breadth first search traversal from "beginWord". beginWord and each word in  wordList form the nodes of my graph. Starting from "beginWord", I try to find the shortest path to endWord. BFS is guaranteed to return the shortest path because all nodes at level k are explored before nodes at level k + 1.

Instead of precomputing the neighbours by doing a pairwise comparison of all words in wordList, I generate and check for neighbours on the fly, during BFS. For each node popped out of the queue, I vary one character at a time and check if it occurs in wordList. If yes, then it is a valid neighbour. if that neighbour is not yet visited, then it is pushed into the queue and marked as visited.

Time complexity:

In BFS, at most "n" words (nodes) get pushed into and popped out of the queue. Generating neighbours for each word is the bottle neck. If the length of each word is L, then I am trying out 26 * L possibilities for each work. If it takes O(L) time to create each new potential neighbour, then total time taken for BFS is O(n * 26 * L * L).

    To make it even faster in practice, we can use bidirectional BFS, where we start the search from beginWord and endWord separately, and then meet in the middle.
    */
    bool expandFrontier(unordered_set<string>& currFrontier, unordered_set<string>& visited, unordered_set<string>& wordSet, unordered_set<string>& otherFrontier)
    {
        unordered_set<string> nextFrontier;

        for (string word : currFrontier)
        {
            for (int i = 0; i < word.size(); i++)
            {
                string nei = word;
                for (int j = 97; j <= 122; j++)
                {
                    char newChar = (char)j;

                    nei[i] = newChar;

                    if (wordSet.count(nei) > 0 && visited.count(nei) == 0)
                    {
                        nextFrontier.insert(nei);
                        visited.insert(nei);

                        if (otherFrontier.count(nei) > 0)
                            return true;
                    }
                }
            }
        }

        currFrontier = nextFrontier;
        return false;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        if (wordSet.count(endWord) == 0)
            return 0;

        unordered_set<string> s1, s2;
        s1.insert(beginWord);
        s2.insert(endWord);

        int level1 = 1, level2 = 1;

        unordered_set<string> visited1, visited2;
        visited1.insert(beginWord);
        visited2.insert(endWord);

        while(s1.size() > 0 && s2.size() > 0)
        {
            bool overlapFound = false;

            if (s1.size() <= s2.size())
            {
                overlapFound = expandFrontier(s1, visited1, wordSet, s2);
                level1++;
            }
            else
            {
                overlapFound = expandFrontier(s2, visited2, wordSet, s1);
                level2++;
            }

            if (overlapFound)
                return level1 + level2 - 1;
        }

        return 0;
    }
};
