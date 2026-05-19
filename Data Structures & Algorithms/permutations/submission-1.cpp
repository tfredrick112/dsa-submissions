class Solution {
public:
    // Time complexity - O(n . n!) : There are n! valid permutations, and O(n) is the time taken to copy each into the result
    // Space - O(n) for recursion stack, O(n) for curr and selected arrays; O(n . n!) -> output space
    void backtrack(vector<int>& nums, vector<bool>& selected, vector<int>& curr, vector<vector<int>>& result)
    {
        if (curr.size() == nums.size())
        {
            result.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (selected[i] == false)
            {
                selected[i] = true;
                curr.push_back(nums[i]);

                backtrack(nums, selected, curr, result);

                selected[i] = false;
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> result;
        vector<int> curr;
        vector<bool> selected(nums.size(), false);
        backtrack(nums, selected, curr, result);
        return result;
    }
};
