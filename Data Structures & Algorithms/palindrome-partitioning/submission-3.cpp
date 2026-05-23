class Solution {
public:
    // Time complexity is O(n * 2^n). There are a total of 2^n possible partitionings - at every
    // index, there are 2 choices - whether to partition there or not.
    // O(n) time to copy a partitioning into the result vector, so total time complexity is O(n * 2 ^ n)
    // Space complexity = O(n^2) for the DP table + O(n) for the curr vector {output space = O(n * 2^n)}

    vector<vector<bool>> dp;

    void buildDpTable(string& s)
    {
        int n = s.size();
        dp.assign(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++)
        {
            dp[i][i] = true; // substrings of length 1 are always palindromes
        }

        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
                dp[i][i + 1] = true;
        }

        for (int len = 3; len <= n; len++)
        {
            for (int i = 0; i <= n - len; i++)
            {
                int j = i + len - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1])
                {
                    dp[i][j] = true;
                }
            }
        }
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
            if (dp[index][j])
            {
                curr.push_back(s.substr(index, j - index + 1));
                backtrack(s, j + 1, curr, result);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        buildDpTable(s);
        vector<vector<string>> result;
        vector<string> curr;

        backtrack(s, 0, curr, result);

        return result;
    }
};
