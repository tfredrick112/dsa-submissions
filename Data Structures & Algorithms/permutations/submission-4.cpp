class Solution {
public:
    // Time complexity - O(n^2 . n!) : There are n! valid permutations, but we need to do n insert operations to build a permutation and each each insert is O(n)
    // Space complexity is also O(n ^ 2 . n!) as we store intermediate permutation results in every recursion level
    vector<vector<int>> generatePermutations(vector<int>& nums)
    {
        if (nums.size() == 0)
            return {{}};

        vector<int> tmp = vector<int>(nums.begin() + 1, nums.end());
        vector<vector<int>> perms = generatePermutations(tmp);
        vector<vector<int>> result;

        for (const auto& p : perms)
        {
            for (int i = 0; i <= p.size(); i++)
            {
                vector<int> p_copy = p;
                p_copy.insert(p_copy.begin() + i, nums[0]);
                result.push_back(p_copy);
            }
        }

        return result;
    }
    vector<vector<int>> permute(vector<int>& nums)
    {
        return generatePermutations(nums);
    }
};
