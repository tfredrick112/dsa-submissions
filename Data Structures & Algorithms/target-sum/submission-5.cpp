class Solution {
public:
    vector<vector<int>> dp;
    int totalSum = 0;
    int findWaysHelper(vector<int>& nums, int i, int total, int target)
    {
        if (i == nums.size())
        {
            return total == target ? 1 : 0;
        }

        if (dp[i][total + totalSum] != INT_MIN)
            return dp[i][total + totalSum];

        dp[i][total + totalSum] = findWaysHelper(nums, i + 1, total + nums[i], target) + findWaysHelper(nums, i + 1, total - nums[i], target);

        return dp[i][total + totalSum];
    }
    int findTargetSumWays(vector<int>& nums, int target)
    {
        totalSum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        
        dp.assign(n, vector<int>(totalSum * 2 + 1, INT_MIN));

        return findWaysHelper(nums, 0, 0, target);
    }
};
