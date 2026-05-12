class Solution {
public:
    // This solution takes O(n) time and O(1) space.
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();

        vector<int> curr(2, 0), front1(2, 0), front2(2, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                if (buy == 1)
                {
                    curr[buy] = max(-prices[i] + front1[0], 0 + front1[1]);
                }
                else
                {
                    curr[buy] = max(prices[i] + front2[1], 0 + front1[0]);
                }

                front2 = front1;
                front1 = curr;
            }
        }

        return curr[1];
    }
};
