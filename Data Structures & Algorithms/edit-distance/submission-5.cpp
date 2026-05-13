class Solution {
public:
    int deleteCost = 1;
    int insertCost = 1;
    int replaceCost = 1;

    // Time complexity - O(m*n)
    // Space complexity - O(n) used only one 1-D array.
    // Instead of using prev as an array, we store only the diagonal from the previous iteration.
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
            int prev = dp[0];
            dp[0] = prev + deleteCost;

            for (int j = 1; j <= n; j++)
            {
                int temp = dp[j];

                int replacementCost = word1[i-1] == word2[j-1] ? 0 : replaceCost;

                dp[j] = min({
                    prev + replacementCost,
                    dp[j] + deleteCost,
                    dp[j - 1] + insertCost
                });

                prev = temp;
            }
        }

        return dp[n];
    }
};
