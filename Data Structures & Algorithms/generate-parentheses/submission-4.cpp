class Solution {
public:
    void backtrack(int close, int open, string& curr, vector<string>& result)
    {
        if (close == 0 && open == 0)
        {
            result.push_back(curr);
            return;
        }

        if (close < open)
            return;

        if (close > 0)
        {
            curr += ')';
            close--;

            backtrack(close, open, curr, result);

            close++;
            curr.pop_back();
        }

        if (open > 0)
        {
            curr += '(';
            open--;

            backtrack(close, open, curr, result);

            open++;
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        string curr;

        int close = n, open = n;

        backtrack(close, open, curr, result);
        return result;
    }
};
