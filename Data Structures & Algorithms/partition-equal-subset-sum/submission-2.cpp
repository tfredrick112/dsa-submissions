class Solution {
public:
    // Time complexity - O(n * t), space - O(t)
    // t = half of the sum of all numbers in nums
    bool canPartition(vector<int>& nums)
    {
        int total = 0;
        for (const int& num : nums)
            total += num;

        if (total % 2 != 0)
            return false;

        int n = nums.size();

        vector<bool> dp(total/2 + 1);
        vector<bool> prev;

        // trivial case: we can always get a sum of 0 by choosing nothing
        dp[0] = true;

        // trivial case: We cannot any positive sum without choosing any numbers
        for (int j = 1; j <= total/2; j++)
        {
            dp[j] = false;
        }

        for (int i = 1; i <= n; i++)
        {
            prev = dp;
            for (int j = 1; j <= total/2; j++)
            {
                if (nums[i - 1] <= j)
                {
                    dp[j] = prev[j] || prev[j - nums[i - 1]];
                }
                else
                {
                    dp[j] = prev[j];
                }
            }
        }

        return dp[total/2];
    }
};
