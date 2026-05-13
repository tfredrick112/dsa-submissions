class Solution {
public:
    // Time complexity - O(mn), Space complexity - O(mn)
    bool isInterleave(string s1, string s2, string s3)
    {
        int m = s1.size(), n = s2.size();
        if (m + n != s3.size())
            return false;

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));

        // dp[i][j] is true if the substrings s1[i:] and s2[j:] can be interleaved
        // to create s3[k:] where k = i + j

        dp[m][n] = true;

        for (int i = m - 1; i>=0; i--)
        {
            dp[i][n] = dp[i + 1][n] && s1[i] == s3[i + n];
        }

        for (int j = n - 1; j>=0;j--)
        {
            dp[m][j] = dp[m][j + 1] && s2[j] == s3[m + j];
        }

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                int k = i + j;
                if (s1[i] == s3[k] && s2[j] == s3[k])
                {
                    dp[i][j] = dp[i + 1][j] || dp[i][j + 1];
                }
                else if (s1[i] == s3[k])
                {
                    dp[i][j] = dp[i + 1][j];
                }
                else if (s2[j] == s3[k])
                {
                    dp[i][j] = dp[i][j + 1];
                }
                else
                {
                    dp[i][j] = false;
                }
            }
        }

        return dp[0][0];
    }
};
