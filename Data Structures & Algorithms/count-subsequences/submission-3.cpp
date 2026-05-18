class Solution {
public:
    // Time complexity = O(mn), space complexity = O(mn)
    int numDistinct(string s, string t)
    {
        int m = s.size(), n = t.size();
        if (m < n)
            return 0;
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // dp[i][0] should be 1 -> there is 1 way to get an empty string as subsequence of s.
        for (int i = 0; i <= m; i++)
        {
            dp[i][0] = 1;
        }

        // dp[0][j] should be 0 for j = 1 to j = n => there are no characters in s, so we cannot
        // get a subsequence of non-zero length from it.
        // this is already handled during initialization.

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[m][n];
    }
};
