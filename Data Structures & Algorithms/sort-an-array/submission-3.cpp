class Solution {
public:
    // Quick sort, O(n log n) time complexity ON AVERGAE and O(1) space complexity
    // O(log n) space for the recursion stack
    // Median of 3 (low, mid, high) approach for selecting the pivot -> protection
    // against adversarial inputs.
    // Always selecting the first or last element as pivot degrades to O(n^2) worst case
    // for an already sorted, reverse-sorted or nearly-sorted input array.

    //  Extra space optimization - we recurse only on the smaller partition and for the larger partition, it will be handled by iteration. It has to be further broken into smaller partitions before we recurse on it - guarantees O(log n) recursion stack space evn for adversarial inputs.
    
    int partition(vector<int>& arr, int low, int high)
    {
        int mid = low + (high - low)/2;
        int pivotIndex = 0;
        if (arr[low] >= arr[mid] && arr[low] >= arr[high])
            pivotIndex = arr[mid] > arr[high] ? mid : high;
        else if (arr[mid] >= arr[low] && arr[mid] >= arr[high])
            pivotIndex = arr[low] > arr[high] ? low : high;
        else
            pivotIndex = arr[low] > arr[mid] ? low : mid;

        int pivot = arr[pivotIndex];
        swap(arr[low], arr[pivotIndex]);

        int i = low, j = high;

        while (i < j)
        {
            while(i <= high && arr[i] <= pivot)
                i++;

            while (j >= low && arr[j] > pivot)
                j--;

            if (i < j)
                swap(arr[i], arr[j]);
        }

        swap(arr[low], arr[j]);
        return j;
    }
    void quickSort(vector<int>& arr, int low, int high)
    {
        while (low < high)
        {
            int partitionIndex = partition(arr, low, high);

            if (partitionIndex - low < high - partitionIndex)
            {
                quickSort(arr, low, partitionIndex - 1);
                low = partitionIndex + 1;
            }
            else
            {
                quickSort(arr, partitionIndex + 1, high);
                high = partitionIndex - 1;
            }
        }
    }
    vector<int> sortArray(vector<int>& nums)
    {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};