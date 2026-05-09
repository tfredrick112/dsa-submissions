class Solution {
public:
    // Space optimized bottom-up solution
    int findTargetSumWays(vector<int>& nums, int target)
    {
        unordered_map<int, int> dp;
        dp[0] = 1;

        for(int i = 0; i < nums.size(); i++)
        {
            unordered_map<int, int> nextDp;
            for(auto& [sum, count] : dp)
            {
                nextDp[sum + nums[i]] += count;
                nextDp[sum - nums[i]] += count;
            }

            dp = nextDp;
        }

        return dp[target];
    }
};
