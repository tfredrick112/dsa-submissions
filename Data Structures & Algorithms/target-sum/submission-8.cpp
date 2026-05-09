class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target)
    {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if (target < -totalSum || target > totalSum)
            return 0;

        int size = 2 * totalSum + 1;
        vector<vector<int>> dp(n + 1, vector<int>(size, 0));
        dp[0][0 + totalSum] = 1;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (dp[i][j] == 0) continue;
                dp[i + 1][j + nums[i]] += dp[i][j];
                dp[i + 1][j - nums[i]] += dp[i][j];
            }
        }

        return dp[n][target + totalSum];
    }
};
