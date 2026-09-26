class Solution {
public:
    // O(E log E) time complexity -> as this graph contains an edge between every possible pair of nodes, it is a dense graph and the E log E simplifies to O(V^2 log V)
    // Space -> O(E) to store all edges + O(V) for the parent and rank arrays; as E approaches V^2 due to the dense nature of the graph, the space complexity is O(V^2).
    vector<int> parent;
    vector<int> rank;
    int find(int i)
    {
        if (parent[i] != i)
        {
            parent[i] = find(parent[i]);
        }

        return parent[i];
    }

    bool unionOperation(int x, int y)
    {
        int xRoot = find(x);
        int yRoot = find(y);
        if (xRoot == yRoot)
        {
            return false;
        }

        if (rank[xRoot] > rank[yRoot])
        {
            parent[yRoot] = xRoot;
        }
        else if (rank[yRoot] > rank[xRoot])
        {
            parent[xRoot] = yRoot;
        }
        else
        {
            parent[xRoot] = yRoot;
            rank[yRoot] += 1;
        }

        return true;
    }
    int minCostConnectPoints(vector<vector<int>>& points)
    {
        int n = points.size();
        if (n == 0 || n == 1)
            return 0;

        vector<vector<int>> edges;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({dist, i, j});
            }
        }

        sort(edges.begin(), edges.end());

        int totalCost = 0;
        int edgeCount = 0;

        parent.resize(n);
        rank.assign(n, 1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }

        for (const auto& edge : edges)
        {
            int d = edge[0], u = edge[1], v = edge[2];

            bool unionPerformed = unionOperation(u, v);
            if (unionPerformed)
            {
                edgeCount += 1;
                totalCost += d;

                if (edgeCount == n - 1)
                    return totalCost;
            }
        }

        return totalCost;
    }
};
