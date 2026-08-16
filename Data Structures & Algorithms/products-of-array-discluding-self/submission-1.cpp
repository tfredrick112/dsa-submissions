class Solution {
public:
    // This is a O(n) time and O(1) space solution
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> answer(n, 1);

        // store the left products directly into the answer array
        answer[0] = 1;
        for (int i = 1; i < n; i++)
        {
            answer[i] = answer[i - 1] * nums[i - 1];
        }

        int rightProduct = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            answer[i] = answer[i] * rightProduct;
            rightProduct *= nums[i];
        }

        return answer;
    }
};
