class Solution {
public:
    // O(n^2) time and O(n) space
    // int lengthOfLIS(vector<int>& nums)
    // {
    //     int n = nums.size();
    //     if (n == 0)
    //         return 0;

    //     vector<int> dp(n);
    //     int maxLen = 1;
    //     dp[0] = 1; // for an array with only 1 element, the length of LIS = 1

    //     for (int i = 1; i < n; i++)
    //     {
    //         dp[i] = 1;
    //         for (int j = 0; j < i; j++)
    //         {
    //             if (nums[i] > nums[j])
    //             {
    //                 dp[i] = max(dp[i], 1 + dp[j]);
    //             }
    //         }

    //         maxLen = max(maxLen, dp[i]);
    //     }

    //     return maxLen;
    // }

    int binarySearch(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left)/2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return left;
    }

    // O(n log n) time and O(n) space
    int lengthOfLIS(vector<int>& nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;

        vector<int> ans;
        // ans[i] is the smallest element that can be the last element of an increasing subsequence of length i + 1

        // The final size of ans will the answer i.e. length of the LIS of the input

        ans.push_back(nums[0]);

        for (int i = 1; i < n; i++)
        {
            if (nums[i] > ans.back())
            {
                ans.push_back(nums[i]);
            }
            else
            {
                // Find the index of the first element that is equal to or greater than nums[i]
                int index = binarySearch(ans, nums[i]);
                ans[index] = nums[i];
            }
        }

        return ans.size();
    }
};
