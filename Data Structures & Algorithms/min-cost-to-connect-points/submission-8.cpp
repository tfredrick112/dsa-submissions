class Solution {
public:
    // Time complexity - O(V^2), space complexity = O(V)
    int minKey(vector<bool>& mstSet, vector<int>& key)
    {
        int minVal = INT_MAX, min_index;
        for (int j = 0; j < mstSet.size(); j++)
        {
            if (!mstSet[j] && key[j] < minVal)
            {
                minVal = key[j];
                min_index = j;
            }
        }

        return min_index;
    }
    int minCostConnectPoints(vector<vector<int>>& points)
    {
        int n = points.size();
        if (n == 0 || n == 1)
            return 0;

        vector<bool> mstSet(n, false);
        vector<int> key(n, INT_MAX);
        int totalCost = 0;

        key[0] = 0;

        for (int count = 1; count <= n; count++)
        {
            // Find the vertex with the lowest key value (from the set of vertices NOT yet in the MST)
            int u = minKey(mstSet, key);

            mstSet[u] = true;
            totalCost += key[u];

            for (int v = 0; v < n; v++)
            {
                if (!mstSet[v])
                {
                    int dist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    if (key[v] > dist)
                    {
                        key[v] = dist;
                    }
                }
            }

        }

        return totalCost;
    }
};
