class Solution {
public:
    // Time complexity: O(mn); Space complexity: O(mn) for the memo and O(m + n) for the recursion stack
    bool f(string& s, string& p, int m, int n, vector<vector<int>>& dp)
    {
        if (dp[m][n] != -1)
            return dp[m][n];

        if (n == 0)
            return dp[m][n] = m == 0;

        if (m == 0)
        {
            if (p[n - 1] != '*')
                return dp[m][n] = false;
            else
                return dp[m][n] = f(s, p, m, n - 2, dp);
        }

        if (p[n - 1] == '.' || p[n - 1] == s[m - 1])
            return dp[m][n] = f(s, p, m - 1, n - 1, dp);

        if (p[n - 1] != '*')
            return dp[m][n] = false;

        if (p[n - 2] == '.' || p[n - 2] == s[m - 1])
            return dp[m][n] = f(s, p, m - 1, n, dp) || f(s, p, m, n - 2, dp);
        else
            return dp[m][n] = f(s, p, m, n - 2, dp);
    }
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return f(s, p, m, n, dp);
    }
};
