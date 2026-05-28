class Solution {
public:
    int findPivot(vector<int>& nums)
    {
        int l = 0, r = nums.size() - 1;

        while (l <= r)
        {
            if (nums[l] <= nums[r])
            {
                return l;
            }

            int mid = (l + r)/2;
            if (mid > 0 && nums[mid] < nums[mid - 1])
            {
                return mid;
            }

            if (nums[l] <= nums[mid])
            {
                l = mid + 1;
            }
            else if (nums[mid] < nums[r])
            {
                r = mid;
            }
        }

        return l;
    }

    int binarySearch(vector<int>& nums, int target, int l, int r)
    {
        while (l <= r)
        {
            int mid = l + (r - l)/2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] > target)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return -1;
    }

    int search(vector<int>& nums, int target)
    {
        int minIndex = findPivot(nums);

        int resultIndex = binarySearch(nums, target, 0, minIndex);
        if (resultIndex != -1)
            return resultIndex;

        resultIndex = binarySearch(nums, target, minIndex, nums.size() - 1);
        
        return resultIndex;
    }
};
