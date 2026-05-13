class Solution {
public:

    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& result, int i, int j, int m, int n)
    {
        if (result[i][j] != -1)
            return result[i][j];

        int maxLenNeighborPath = 0;

        if (i > 0 && matrix[i - 1][j] > matrix[i][j])
        {
            maxLenNeighborPath = max(maxLenNeighborPath, dfs(matrix, result, i - 1, j, m, n));
        }

        if (i < m - 1 && matrix[i + 1][j] > matrix[i][j])
        {
            maxLenNeighborPath = max(maxLenNeighborPath, dfs(matrix, result, i + 1, j, m, n));
        }

        if (j > 0 && matrix[i][j - 1] > matrix[i][j])
        {
            maxLenNeighborPath = max(maxLenNeighborPath, dfs(matrix, result, i, j - 1, m, n));
        }

        if (j < n - 1 && matrix[i][j + 1] > matrix[i][j])
        {
            maxLenNeighborPath = max(maxLenNeighborPath, dfs(matrix, result, i, j + 1, m, n));
        }

        result[i][j] = 1 + maxLenNeighborPath;
        return result[i][j];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> result(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (result[i][j] == -1)
                {
                    int temp = dfs(matrix, result, i, j, m, n);
                }
            }
        }

        int maxLen = INT_MIN;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                maxLen = max(maxLen, result[i][j]);
            }
        }
        return maxLen;
    }
};
