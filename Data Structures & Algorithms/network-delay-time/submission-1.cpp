class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& edge : times)
        {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u - 1].push_back({v - 1, w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        vector<bool> finalized(n, false);
        vector<int> dist(n, INT_MAX);

        dist[k - 1] = 0;
        minHeap.push({0, k - 1});

        while (!minHeap.empty())
        {
            auto [d, u] = minHeap.top();
            minHeap.pop();

            if (finalized[u])
                continue;

            finalized[u] = true;

            for (pair<int, int> nei : adj[u])
            {
                int v = nei.first, w = nei.second;
                if (!finalized[v] && dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    minHeap.push({dist[v], v});
                }
            }
        }

        int minTime = *max_element(dist.begin(), dist.end());
        if (minTime == INT_MAX)
            return -1;
        else
            return minTime;
    }
};
