class Solution {
public:
    void backtrack(vector<int>& nums, int index, vector<int>& curr, vector<vector<int>>& result)
    {
        if (index == nums.size())
        {
            result.push_back(curr);
            return;
        }

        result.push_back(curr);

        for (int i = index; i < nums.size(); i++)
        {
            if (i > index && nums[i] == nums[i - 1])
                continue;

            curr.push_back(nums[i]);
            backtrack(nums, i + 1, curr, result);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        vector<vector<int>> result;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, curr, result);
        return result;
    }
};
