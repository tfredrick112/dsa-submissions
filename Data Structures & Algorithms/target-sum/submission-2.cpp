class Solution {
public:
    int findWaysHelper(vector<int>& nums, int lastIndex, int target)
    {
        if (lastIndex == -1)
        {
            if (target == 0)
                return 1;
            else
                return 0;
        }

        return findWaysHelper(nums, lastIndex - 1, target + nums[lastIndex]) + findWaysHelper(nums, lastIndex - 1, target - nums[lastIndex]);
    }

    int findTargetSumWays(vector<int>& nums, int target)
    {
        return findWaysHelper(nums, nums.size() - 1, target);
    }
};
