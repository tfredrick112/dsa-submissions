class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        // search the last column - you will either find the target or the "insertion point"
        // Use the insertion point to narrow down your search to just one row

        int top = 0, bottom = m - 1;
        int insertionPoint = -1;
        while(top<=bottom)
        {
            int mid = (top + bottom)/2;
            if (matrix[mid][n - 1]==target)
            {
                insertionPoint = mid;
                break;
            }
            else if (matrix[mid][n - 1] > target)
            {
                bottom = mid - 1;
            }
            else
            {
                top = mid + 1;
            }
        }

        if (insertionPoint == -1)
            insertionPoint = top;

        if (insertionPoint > m - 1)
        {
            return false;
        }

        if(matrix[insertionPoint][n - 1] == target)
        {
            return true;
        }

        int left = 0, right = n - 1;
        while(left <= right)
        {
            int mid = (left + right)/2;
            if (matrix[insertionPoint][mid]==target)
            {
                return true;
            }
            else if (matrix[insertionPoint][mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return false;
    }
};
