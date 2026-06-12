class Solution {
public:
    // This is an O(n^2 log n) solution.
    // O(n^2) for each BFS as there are n^2 nodes, and O(log n) for finding the optimal value of t using binary search
    vector<vector<int>> directions = {
        {-1, 0}, {1, 0}, {0, 1}, {0, -1}
    };
    
    bool isReachable(vector<vector<int>>& grid, int t, int n)
    {
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;

        while(!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            if (x == n - 1 && y == n - 1)
                return true;

            for (const auto& d : directions)
            {
                int x_new = x + d[0], y_new = y + d[1];

                if (x_new >= 0 && x_new < n && y_new >= 0 && y_new < n)
                {
                    if (!visited[x_new][y_new] && grid[x_new][y_new] <= t)
                    {
                        q.push({x_new, y_new});
                        visited[x_new][y_new] = true;
                    }
                }
            }
        }

        return false;
    }

    int swimInWater(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int maxTime = n * n - 1;
        int minTime = max(grid[0][0], grid[n - 1][n - 1]);

        int minValidTime = maxTime;

        int l = minTime, r = maxTime;
        while(l <= r)
        {
            int mid = l + (r - l)/2;
            if (isReachable(grid, mid, n))
            {
                minValidTime = min(minValidTime, mid);
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return minValidTime;
    }
};
