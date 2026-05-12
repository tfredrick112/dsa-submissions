class Solution {
public:
    // This is the tabulation or bottom-up approach
    // It is easy to understand this if you read it side-by-side with the memoization approach
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        // dp[i][j] is the maximum profit that you get starting on day with index i and
        // with a starting state of j

        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                if (buy == 1)
                {
                    dp[i][buy] = max(-prices[i] + dp[i + 1][0], 0 + dp[i + 1][1]);
                }
                else
                {
                    dp[i][buy] = max(prices[i] + dp[i + 2][1], 0 + dp[i + 1][0]);
                }
            }
        }

        return dp[0][1];
    }
};
