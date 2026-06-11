class Solution {
public:
    void dfs(string node, unordered_map<string, vector<string>>& adj, vector<string>& result)
    {
        while (!adj[node].empty())
        {
            string dest = adj[node].back();
            adj[node].pop_back();
            dfs(dest, adj, result);
        }

        result.push_back(node);
    }

    // O(E log E) - dominated by the sorting
    vector<string> findItinerary(vector<vector<string>>& tickets)
    {
        sort(tickets.rbegin(), tickets.rend());

        unordered_map<string, vector<string>> adj;

        for (const auto& ticket : tickets)
        {
            adj[ticket[0]].push_back(ticket[1]);
        }

        vector<string> result;

        dfs("JFK", adj, result);

        reverse(result.begin(), result.end());

        return result;
    }
};
