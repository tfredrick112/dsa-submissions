class Solution {
public:
    // Iterative solution. This is also O(E log E) due to sorting.
    vector<string> findItinerary(vector<vector<string>>& tickets)
    {
        unordered_map<string, vector<string>> adj;

        sort(tickets.rbegin(), tickets.rend());

        for (const auto& t : tickets)
        {
            adj[t[0]].push_back(t[1]);
        }

        vector<string> result;

        stack<string> st;
        st.push("JFK");

        while(!st.empty())
        {
            string node = st.top();

            if (adj[node].empty())
            {
                result.push_back(node);
                st.pop();
            }
            else
            {
                string dest = adj[node].back();
                adj[node].pop_back();
                st.push(dest);
            }
        }

        reverse(result.begin(), result.end());

        return result;
    }
};
