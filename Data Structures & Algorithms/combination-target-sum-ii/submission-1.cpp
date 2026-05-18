class Solution {
public:
    // Time complexity = O(n . 2^n): There are 2^n possible subsets and it takes O(n) time to copy a subset into the result array.
    // Space: O(n) -> recursion stack and the curr array; output space - O(n . 2^ n)
    void backtrack(vector<int>& nums, int index, int sum, int target, vector<int>& curr, vector<vector<int>>& result)
    {
        if (sum == target)
        {
            result.push_back(curr);
            return;
        }

        for(int i = index; i < nums.size(); i++)
        {
            if (i > index && nums[i] == nums[i - 1])
                continue;

            if (sum + nums[i] > target)
                return;

            curr.push_back(nums[i]);
            backtrack(nums, i + 1, sum + nums[i], target, curr, result);
            curr.pop_back();
        }
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, 0, 0, target, curr, result);
        return result;
    }
};
