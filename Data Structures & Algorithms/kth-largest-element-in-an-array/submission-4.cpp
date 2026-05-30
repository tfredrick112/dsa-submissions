class Solution {
public:
    // Counting sort approach - good when the range is very small
    // Time complexity - O(n + range) -> O(n) time to calculate min, max and populate the freq array,
    // O(range) time for the main for loop
    // Space  = O(range)
    int findKthLargest(vector<int>& nums, int k)
    {
        int l = *min_element(nums.begin(), nums.end());
        int h = *max_element(nums.begin(), nums.end());

        int range = h - l;

        vector<int> freq(range + 1, 0);

        for (int& num : nums)
        {
            freq[num - l]++;
        }

        int count = 0;

        for (int i = range; i >= 0; i--)
        {
            count += freq[i];
            if (count >= k)
                return i + l;
        }

        return 0;
    }
};
