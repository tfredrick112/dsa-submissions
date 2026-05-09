class Solution {
public:
    int findWaysHelper(vector<int>& nums, int lastIndex, int target, unordered_map<int, unordered_map<int, int>>& mp)
    {
        if (lastIndex == -1)
        {
            if (target == 0)
                return 1;
            else
                return 0;
        }

        if (mp.find(lastIndex) != mp.end())
        {
            if (mp[lastIndex].find(target) != mp[lastIndex].end())
            {
                return mp[lastIndex][target];
            }
        }
        
        mp[lastIndex][target] = findWaysHelper(nums, lastIndex - 1, target + nums[lastIndex], mp) + findWaysHelper(nums, lastIndex - 1, target - nums[lastIndex], mp);

        return mp[lastIndex][target];
    }

    int findTargetSumWays(vector<int>& nums, int target)
    {
        unordered_map<int, unordered_map<int, int>> mp;

        return findWaysHelper(nums, nums.size() - 1, target, mp);
    }
};
