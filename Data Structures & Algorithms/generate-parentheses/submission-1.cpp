class Solution {
public:
    void backtrack(int lenPerm, unordered_map<char, int>& counts, string& curr, int score, vector<string>& result)
    {
        if (curr.size() == lenPerm)
        {
            result.push_back(curr);
            return;
        }

        for (const auto& [ch, count] : counts)
        {
            if (count <= 0)
                continue;

            int updatedScore = score + (ch == '(' ? 1 : -1);
            if (updatedScore < 0)
                continue;

            curr += ch;
            counts[ch]--;

            backtrack(lenPerm, counts, curr, updatedScore, result);

            curr.pop_back();
            counts[ch]++;
        }
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        string curr;

        unordered_map<char, int> counts = {
            {'(', n}, {')', n}
        };

        backtrack(2 * n, counts, curr, 0, result);
        return result;
    }
};
