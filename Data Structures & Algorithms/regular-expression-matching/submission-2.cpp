class Solution {
public:
    // Bottom up approach
    // Time complexity: O(mn); Space complexity: O(mn)
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));

        dp[0][0] = true;// both s and p are empty strings, so it is a match

        // for non-empty s, with an empty pattern p, it cannot be a match
        for (int i = 1; i <= m; i++)
        {
            dp[i][0] = false;
        }

        for (int j = 1; j <= n; j++)
        {
            if (p[j - 1] != '*')
                dp[0][j] = false;
            else
                dp[0][j] = dp[0][j - 2];
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[j - 1] != '*')
                {
                    dp[i][j] = false;
                }
                else if (p[j - 2] == '.' || p[j - 2] == s[i - 1])
                {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 2];
                }
                else
                {
                    dp[i][j] = dp[i][j - 2];
                }
            }
        }

        return dp[m][n];
    }
};
