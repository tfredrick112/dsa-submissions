class Solution {
public:
    // Bottom up approach
    // Time complexity: O(mn); Space complexity: O(n)
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();
        vector<bool> dp(n + 1);

        dp[0] = true;// both s and p are empty strings, so it is a match

        for (int j = 1; j <= n; j++)
        {
            if (p[j - 1] != '*')
                dp[j] = false;
            else
                dp[j] = dp[j - 2];
        }

        for (int i = 1; i <= m; i++)
        {
            vector<bool> prev = dp;
            dp[0] = false; // there cannot be a match for a non-empty s with an empty pattern p

            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.')
                {
                    dp[j] = prev[j - 1];
                }
                else if (p[j - 1] != '*')
                {
                    dp[j] = false;
                }
                else if (p[j - 2] == '.' || p[j - 2] == s[i - 1])
                {
                    dp[j] = prev[j] || dp[j - 2];
                }
                else
                {
                    dp[j] = dp[j - 2];
                }
            }
        }

        return dp[n];
    }
};
