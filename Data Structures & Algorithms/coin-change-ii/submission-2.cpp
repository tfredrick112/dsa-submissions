class Solution {
public:
    // numWays(coins, amount, idx, dp) -> number of ways to get a sum equal to amount by using entries from the coins array, from index idx onwards
    int numWays(vector<int>& coins, int amount, int idx, vector<vector<int>>& dp)
    {
        if (amount == 0)
        {
            // amount has become 0, so we have found a valid way to get a sum equal to the original input
            return 1;
        }
        else if (amount < 0)
        {
            return 0;
        }

        if (dp[idx][amount] != -1)
            return dp[idx][amount];
        
        int total = 0;

        // The loop starts at idx, because we do not want to create duplicate solutions. For example, if we are trying to get a sum of 4 using [1,2,3]
        // [1,3] and [3,1] will add up to 4, but we have to avoid such duplicates, so we ensure that we only look ahead, so 1 + 3 will be found, but if
        // 3 is the first number, then it will not use 1 as it is on the left.
        for (int i = idx; i < coins.size(); i++)
        {
            // For idx param, we send i and NOT i + 1, because we have an unlimited supply of coins of each denomination.
            total += numWays(coins, amount - coins[i], i, dp);
        }

        return dp[idx][amount] = total;
    }
    int change(int amount, vector<int>& coins)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return numWays(coins, amount, 0, dp);
    }
};
