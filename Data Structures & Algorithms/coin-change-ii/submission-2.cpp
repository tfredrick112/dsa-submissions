class Solution {
public:
    int numWays(vector<int>& coins, int amount, int idx, vector<vector<int>>& dp)
    {
        if (amount == 0)
        {
            return 1;
        }
        else if (amount < 0)
        {
            return 0;
        }

        if (dp[idx][amount] != -1)
            return dp[idx][amount];
        
        int total = 0;
        for (int i = idx; i < coins.size(); i++)
        {
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
