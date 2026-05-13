class Solution {
public:
    int deleteCost = 1;
    int insertCost = 1;
    int replaceCost = 1;

    // Time complexity - O(m*n)
    // Space complexity - O(n) but we are using 2 1-D arrays, prev and dp
    int minDistance(string word1, string word2)
    {
        int m = word1.size(),n = word2.size();
        vector<int> dp(n + 1);

        // dp[i][j] = edit distance between word1[0:i-1] and word2[0:j-1]
        dp[0] = 0;

        for (int j = 1; j <= n; j++)
        {
            dp[j] = dp[j - 1] + insertCost;
        }

        for (int i = 1; i <= m; i++)
        {
            vector<int> prev = dp;
            dp[0] = prev[0] + deleteCost;

            for (int j = 1; j <= n; j++)
            {
                int replacementCost = word1[i-1] == word2[j-1] ? 0 : replaceCost;

                dp[j] = min({
                    prev[j - 1] + replacementCost,
                    prev[j] + deleteCost,
                    dp[j - 1] + insertCost
                });
            }
        }

        return dp[n];
    }
};
