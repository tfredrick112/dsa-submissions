class Solution {
public:
    // Merge sort, O(n log n) time complexity and O(n) space complexity
    
    // Avoid repeated heap allocation. This logic works when we are running a single
    // threaded merge sort without any parallelization.
    vector<int> temp;

    void merge(vector<int>& arr, int low, int mid, int high)
    {
        int n = high - low + 1;
        int k = 0;
        int i = low, j = mid + 1;

        while (i <= mid && j <= high)
        {
            if (arr[i] <= arr[j])
            {
                temp[k] = arr[i];
                k++;
                i++;
            }
            else
            {
                temp[k] = arr[j];
                k++;
                j++;
            }
        }

        while (i <= mid)
        {
            temp[k] = arr[i];
            k++;
            i++;
        }
        
        while (j <= high)
        {
            temp[k] = arr[j];
            k++;
            j++;
        }

        for(k = 0; k <n; k++)
        {
            arr[low + k] = temp[k];
        }
    }
    void mergeSort(vector<int>& arr, int low, int high)
    {
        if (low < high)
        {
            int mid = low + (high - low)/2;
            mergeSort(arr, low, mid);
            mergeSort(arr, mid + 1, high);
            merge(arr, low, mid, high);
        }
    }
    vector<int> sortArray(vector<int>& nums)
    {
        temp.resize(nums.size());
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};