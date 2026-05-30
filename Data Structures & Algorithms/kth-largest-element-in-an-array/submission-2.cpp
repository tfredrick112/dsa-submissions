class Solution {
public:
    // O(n log k) time
    // O(k) space
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        if(nums.size() == 0)
            return -1;

        for(int num : nums)
        {
            minHeap.push(num);
            if(minHeap.size() > k)
            {
                minHeap.pop();
            }
        }

        return minHeap.top();
    }
};
