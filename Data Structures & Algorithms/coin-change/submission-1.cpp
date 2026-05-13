class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        int n = coins.size();
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = coins[i]; j <= amount; j++)
            {
                if (dp[j - coins[i]] != -1)
                {
                    if (dp[j] != -1)
                        dp[j] = min(1 + dp[j - coins[i]], dp[j]);
                    else
                        dp[j] = 1 + dp[j - coins[i]];
                }
                // else
                // {
                //     dp[j] = dp[j];
                // }
            }
        }

        return dp[amount];
    }
};
