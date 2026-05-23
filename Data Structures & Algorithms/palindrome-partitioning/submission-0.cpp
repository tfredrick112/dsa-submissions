class Solution {
public:
    // Inefficient approach
    vector<vector<string>> f(string& s, int index)
    {
        string curr(1, s[index]);

        if (index == 0)
        {
            return { {curr} };
        }

        vector<vector<string>> partitions = f(s, index - 1);
        vector<vector<string>> result;

        for (const auto& p : partitions)
        {
            vector<string> temp = p;
            temp.push_back(curr);
            result.push_back(temp);

            int n = p.size();
            if (p[n - 1] == curr)
            {
                vector<string> t = p;
                t[n - 1] = p[n - 1] + curr;
                result.push_back(t);
            }

            if (n - 2 >= 0 && p[n - 2] == curr)
            {
                vector<string> t = p;
                t[n - 2] = t[n - 2] + t[n - 1] + curr;
                t.pop_back();
                result.push_back(t);
            }
        }

        return result;
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> result = f(s, s.size() - 1);
        return result;
    }
};
