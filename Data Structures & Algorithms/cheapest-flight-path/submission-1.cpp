class Solution {
public:
    // int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    //     int proxyForInfinity = 1e+9;
    //     vector<int> distance(n, proxyForInfinity);
    //     vector<int> prev;

    //     distance[src] = 0;

    //     for (int i = 1; i <= k + 1; i++)
    //     {
    //         prev = distance;
    //         for(auto& edge : flights)
    //         {
    //             if (prev[edge[0]] == proxyForInfinity)
    //             {
    //                 continue;
    //             }

    //             if (prev[edge[0]] + edge[2] < distance[edge[1]])
    //             {
    //                 distance[edge[1]] = prev[edge[0]] + edge[2];
    //             }
    //         }
    //     }

    //     if (distance[dst] == proxyForInfinity)
    //     {
    //         return -1;
    //     }
    //     else
    //     {
    //         return distance[dst];
    //     }
    // }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
    {
        int inf = 1e9;
        vector<int> dist(n, inf);
        dist[src] = 0;

        vector<int> prev;

        for (int i = 1; i <= k + 1; i++)
        {
            prev = dist;

            for (const auto& edge : flights)
            {
                int u = edge[0], v = edge[1], w = edge[2];
                if (prev[u] == inf)
                    continue;

                if (prev[v] > prev[u] + w)
                {
                    dist[v] = min(dist[v], prev[u] + w);
                }
            }
        }

        if (dist[dst] == inf)
            return -1;
        else
            return dist[dst];
    }
};
