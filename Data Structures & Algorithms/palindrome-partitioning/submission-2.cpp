class Solution {
public:
    // Time complexity is O(n * 2^n). There are a total of 2^n possible partitionings - at every
    // index, there are 2 choices - whether to partition there or not.
    // O(n) time to copy a partitioning into the result vector, so total time complexity is O(n * 2 ^ n)
    // Space complexity = O(n) for the curr vector {output space = O(n * 2^n)}

    bool isPalin(string& s, int i, int j)
    {
        while (i <= j)
        {
            if (s[i] != s[j])
            {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }

    void backtrack(string& s, int index, vector<string>& curr, vector<vector<string>>& result)
    {
        if (index >= s.size())
        {
            result.push_back(curr);
            return;
        }

        for (int j = index; j < s.size(); j++)
        {
            if (isPalin(s, index, j))
            {
                curr.push_back(s.substr(index, j - index + 1));
                backtrack(s, j + 1, curr, result);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> result;
        vector<string> curr;

        backtrack(s, 0, curr, result);

        return result;
    }
};
