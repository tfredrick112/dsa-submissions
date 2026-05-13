class Solution {
public:
    int deleteCost = 1;
    int insertCost = 1;
    int replaceCost = 1;
    int minDistance(string word1, string word2)
    {
        int m = word1.size(),n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        // dp[i][j] = edit distance between word1[0:i-1] and word2[0:j-1]
        dp[0][0] = 0;

        for (int i = 1; i <= m; i++)
        {
            dp[i][0] = dp[i - 1][0] + deleteCost;
        }

        for (int j = 1; j <= n; j++)
        {
            dp[0][j] = dp[0][j - 1] + insertCost;
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int replacementCost = word1[i-1] == word2[j-1] ? 0 : replaceCost;

                dp[i][j] = min({
                    dp[i - 1][j - 1] + replacementCost,
                    dp[i - 1][j] + deleteCost,
                    dp[i][j - 1] + insertCost
                });
            }
        }

        return dp[m][n];
    }
};
