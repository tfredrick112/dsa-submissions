class Solution {
public:
    int change(int amount, vector<int>& coins)
    {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1));

        // dp[i][j] is the number of ways in which we can get a sum equal to j
        // using the elements of coins from index 0 to i - 1
        // The answer will be in dp[n][amount];

        // trivial case: there is exactly 1 way to get a sum of 0
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 1;
        }

        // trivial case: there is no way to get a positive sum without any coins
        for (int j = 1; j <= amount; j++)
        {
            dp[0][j] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= amount; j++)
            {
                if (coins[i - 1] <= j)
                {
                    // dp[i - 1][j] = number of ways to get the sum j without
                    // using coins[i - 1]
                    // dp[i][j - coins[i - 1]] => here we are using the coin coins[i - 1]
                    // Why does the second term have "i" -> because we have an unlimited supply of each coin
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][amount];
    }
};
