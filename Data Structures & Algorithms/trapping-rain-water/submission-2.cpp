class Solution {
public:
    // O(n) time and O(1) space
    int trap(vector<int>& height)
    {
        int n = height.size();

        int totalWater = 0;
        int leftMax = height[0], rightMax = height[n - 1];
        int left = 1, right = n - 2;

        while (left <= right)
        {
            if (leftMax < rightMax)
            {
                totalWater += max(leftMax - height[left], 0);
                leftMax = max(leftMax, height[left]);
                left++;
            }
            else
            {
                totalWater += max(rightMax - height[right], 0);
                rightMax = max(rightMax, height[right]);
                right--;
            }
        }

        return totalWater;
    }
};
