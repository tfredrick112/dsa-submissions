class Solution {
public:
    // Time complexity - O(n * t), space complexity - O(n * t) where n is the size of the input array nums
    // t is half of the sum of all the numbers in the array nums
    // dp[n][total/2] -> is it possible to get a subset with sum equal to total/2 using the elements of nums from
    // index 0 to index n - 1.
    bool canPartition(vector<int>& nums)
    {
        int total = 0;
        for (const int& num : nums)
            total += num;

        if (total % 2 != 0)
            return false;

        int n = nums.size();

        // dp[i][j] => is it possible to get a sum of j using values with index
        // 0 to i - 1 from nums array?
        vector<vector<bool>> dp(n + 1, vector<bool>(total/2 + 1));

        // trivial case: it is always possible to get a sum of 0 - just don't select anything
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = true;
        }

        // trivial case: you cannot get any positive sum if you don't select anything
        for (int j = 1; j <= total/2; j++)
        {
            dp[0][j] = false;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= total/2; j++)
            {
                if (nums[i - 1] <= j)
                {
                    // we can either use the current number or avoid using it
                    // if we already get the sum that we need in this step
                    // without using that number.
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][total/2];
    }
};
