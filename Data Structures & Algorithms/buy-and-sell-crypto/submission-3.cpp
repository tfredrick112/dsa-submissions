class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();

        int leftMin = prices[0];
        int maxProf = 0;

        for (int i = 1; i < n; i++)
        {
            int currentProfit = prices[i] - leftMin;
            maxProf = max(maxProf, currentProfit);

            leftMin = min(leftMin, prices[i]);
        }

        return maxProf;
    }
};
