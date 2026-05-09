class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target)
    {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n + 1);

        // dp[i] is a map that stores: <sum, count> where count is the number
        // of ways you can get 'sum' using the first i numbers from nums

        dp[0][0] = 1; // there is exactly one way to get a sum of 0 using none of the numbers from nums

        for (int i = 0; i < n; i++)
        {
            for (auto& [sum, count] : dp[i])
            {
                dp[i + 1][sum + nums[i]] += count;
                dp[i + 1][sum - nums[i]] += count;
            }
        }

        return dp[n][target];
    }
};
