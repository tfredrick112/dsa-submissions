class Solution {
public:
    int maxProfitHelper(vector<int>& prices, int i, int buy, vector<vector<int>>& dp)
    {
        if (i >= prices.size())
            return 0;

        if (dp[i][buy] != -1)
            return dp[i][buy];

        if (buy == 1)
        {
            // We can either buy a share or do nothing.
            // If we buy, we lose prices[i] and move to i + 1 in a "no buy" state, as we just bought one stock.
            // If we do not buy, then we move to i + 1 in a "buy" state.
            return dp[i][buy] = max(-prices[i] + maxProfitHelper(prices, i + 1, 0, dp),
                                    0 + maxProfitHelper(prices, i + 1, 1, dp));
        }
        else
        {
            // We currently own a stock and we can either sell it or just hold
            // If we sell, we gain prices[i] and we move to i + 2 because of the cooldown.
            // After selling, we go to i + 2 in a "buy" state.
            // If we do not sell, then we just move to the next day in a "no buy" state
            // because we already own one stock and we cannot buy anymore.
            return dp[i][buy] = max(prices[i] + maxProfitHelper(prices, i + 2, 1, dp),
                                    0 + maxProfitHelper(prices, i + 1, 0, dp));
        }
    }
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return maxProfitHelper(prices, 0, 1, dp);
    }
};
