class Solution {
public:
    // This is also O(n^2 log n) but it finds the answer in a single pass
    // Uses a Djikstra based approach.
    // Cost of going from 0,0 to n-1, n-1 is the maximum height encountered along the path
    // So, we have to find the path with the smallest maximum height.
    vector<vector<int>> directions = {
        {0, -1}, {0, 1}, {1, 0}, {-1, 0}
    };
    int swimInWater(vector<vector<int>>& grid)
    {
        int n = grid.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        minHeap.push({grid[0][0], 0, 0});
        visited[0][0] = true;

        while(!minHeap.empty())
        {
            auto curr = minHeap.top();
            minHeap.pop();

            int t = curr[0], x = curr[1], y = curr[2];

            if (x == n - 1 && y == n - 1)
            {
                return t;
            }

            for (const auto& d : directions)
            {
                int x_new = x + d[0], y_new = y + d[1];
                if (x_new >= 0 && x_new < n && y_new >= 0 && y_new < n)
                {
                    if (!visited[x_new][y_new])
                    {
                        visited[x_new][y_new] = true;
                        minHeap.push({max(t, grid[x_new][y_new]), x_new, y_new});
                    }
                }
            }
        }

        return 0;
    }
};
