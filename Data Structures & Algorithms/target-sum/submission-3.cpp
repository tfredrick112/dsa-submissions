class Solution {
public:
    int findWaysHelper(vector<int>& nums, int lastIndex, int target, map<pair<int, int>, int>& mp)
    {
        if (lastIndex == -1)
        {
            if (target == 0)
                return 1;
            else
                return 0;
        }

        pair<int, int> key = make_pair(lastIndex, target);
        if (mp.find(key) != mp.end())
            return mp[key];
        
        mp[key] = findWaysHelper(nums, lastIndex - 1, target + nums[lastIndex], mp) + findWaysHelper(nums, lastIndex - 1, target - nums[lastIndex], mp);

        return mp[key];
    }

    int findTargetSumWays(vector<int>& nums, int target)
    {
        map<pair<int, int>, int> mp;
        return findWaysHelper(nums, nums.size() - 1, target, mp);
    }
};
