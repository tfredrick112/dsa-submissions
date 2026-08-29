class Solution {
public:
    void createAdjacencyList(vector<vector<int>>& edges, vector<vector<int>>& adj, vector<int>& indegree)
    {
        for (const auto& edge : edges)
        {
            indegree[edge[0]]++;
            adj[edge[1]].push_back(edge[0]);
        }
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        createAdjacencyList(prerequisites, adj, indegree);

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> result;
        int finished = 0;

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            result.push_back(curr);
            finished++;

            for (int nei : adj[curr])
            {
                indegree[nei]--;
                if (indegree[nei] == 0)
                {
                    q.push(nei);
                }
            }
        }

        if (finished != numCourses)
            return {};

        return result;
    }
};
