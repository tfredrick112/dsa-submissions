class Solution {
public:
    vector<vector<int>> graph;
    void createAdjacencyMatrix(vector<vector<int>>& points, int V)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = i + 1;j < V; j++)
            {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                graph[i][j] = dist;
                graph[j][i] = dist;
            }
        }
    }
    int minKey(vector<int>& key, vector<bool>& mstSet, int V)
    {
        int minVal = INT_MAX, minIndex = -1;
        for(int i = 0; i < V;i++)
        {
            if (mstSet[i]==false && key[i] < minVal)
            {
                minVal = key[i];
                minIndex = i;
            }
        }

        return minIndex;
    }
    int minCostConnectPoints(vector<vector<int>>& points)
    {
        int V = points.size();
        graph.assign(V, vector<int>(V, 0));
        createAdjacencyMatrix(points, V);

        vector<bool> mstSet(V, false);
        vector<int> key(V, INT_MAX);

        key[0] = 0;

        int res = 0;

        for(int count = 1; count <= V; count++)
        {
            int u = minKey(key, mstSet, V);

            mstSet[u] = true;

            res += key[u];

            for(int i = 0; i < V; i++)
            {
                if (graph[u][i] != 0 && mstSet[i]==false && key[i] > graph[u][i])
                {
                    key[i] = graph[u][i];
                }
            }
        }

        return res;
    }
};
