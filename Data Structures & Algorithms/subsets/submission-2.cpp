class Solution {
public:
    // Time complexity = O(n. 2^n) : There are 2^n possible subsets, and O(n) is the time
    // taken to copy them into the result vector.
    // Space complexity = O(n) for recursion stack & O(n . 2^n) for the output
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
            curr.push_back(nums[i]);
            backtrack(nums, i + 1, curr, result);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> result;
        vector<int> curr;
        backtrack(nums, 0, curr, result);
        return result;
    }
};
