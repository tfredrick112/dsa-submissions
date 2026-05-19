class Solution {
public:
    // Time complexity - O(n . n!) : There are n! valid permutations, and O(n) is the time taken to copy each into the result
    // Space - O(n) for recursion stack, O(n . n!) -> output space
    // The selected array can be eliminated entirely by swapping elements within nums itself, partitioning it into [0, index) (used) and [index, n) (available)
    void backtrack(vector<int>& nums, int index, vector<vector<int>>& result)
    {
        if (index == nums.size())
        {
            result.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            backtrack(nums, index + 1, result);
            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> result;
        backtrack(nums, 0, result);
        return result;
    }
};
