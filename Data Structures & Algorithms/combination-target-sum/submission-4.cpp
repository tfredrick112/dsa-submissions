class Solution {
public:
    void backtrack(vector<int>& nums, int index, int target, int runningTotal, vector<int>& curr, vector<vector<int>>& result)
    {
        if (runningTotal == target)
        {
            result.push_back(curr);
            return;
        }

        for(int j = index; j < nums.size(); j++)
        {
            if (runningTotal + nums[j] > target)
                return;

            curr.push_back(nums[j]);
            backtrack(nums, j, target, runningTotal + nums[j], curr, result);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, target, 0, curr, result);
        return result;
    }
};
