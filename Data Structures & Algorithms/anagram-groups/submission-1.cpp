class Solution {
public:
    // This function is O(n) where n is the length of the string
    string charCountKey(string& s)
    {
        vector<int> counts(26, 0);

        for (char& ch : s)
        {
            counts[ch - 'a']++;
        }

        string result = "";
        for (int i = 0; i < 26; i++)
        {
            result += "," + to_string(counts[i]);
        }

        return result;
    }

    // If m is the total number of strings and n is the length of the longest string,
    // time complexity = O(m * n)
    // space complexity = O(m * n) because we first store the groups and then create the result.
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        int n = strs.size();
        unordered_map<string, vector<string>> groups;
        
        for (int i = 0; i < n; i++)
        {
            string key = charCountKey(strs[i]);
            groups[key].push_back(strs[i]);
        }

        vector<vector<string>> result;
        for (const auto& [k, v] : groups)
        {
            result.push_back(v);
        }

        return result;
    }
};
