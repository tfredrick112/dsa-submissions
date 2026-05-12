class Solution {
public:
    // Space optimized version Space complexity = O(amount); we are using just 1 1-D array.
    int change(int amount, vector<int>& coins)
    {
        int n = coins.size();
        vector<unsigned long long> dp(amount + 1);

        // dp[i][j] is the number of ways in which we can get a sum equal to j
        // using the elements of coins from index 0 to i - 1
        // The answer will be in dp[n][amount];

        // trivial case: there is exactly 1 way to get a sum of 0
        dp[0] = 1;

        // trivial case: there are 0 ways to get a positive sum WITHOUT any coins
        for (int j = 1; j <= amount; j++)
        {
            dp[j] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            //vector<unsigned long long> prev = dp;
            for (int j = 1; j <= amount; j++)
            {
                if (coins[i - 1] <= j)
                {
                    // dp[i - 1][j] = number of ways to get the sum j without
                    // using coins[i - 1]
                    // dp[i][j - coins[i - 1]] => here we are using the coin coins[i - 1]
                    // Why does the second term have "i" -> because we have an unlimited supply of each coin
                    // dp[j] = prev[j] + dp[j - coins[i - 1]];
                    dp[j] = dp[j] + dp[j - coins[i - 1]];
                }
                else
                {
                    //dp[j] = prev[j];
                    dp[j] = dp[j];
                }
            }
        }

        return dp[amount];
    }
};
