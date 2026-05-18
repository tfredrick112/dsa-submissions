class Solution {
public:
    // Bottom up approach
    // Time complexity: O(mn); Space complexity: O(n) using just 1 1-D array
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
            int prev = dp[0];
            dp[0] = false; // there cannot be a match for a non-empty s with an empty pattern p

            for (int j = 1; j <= n; j++)
            {
                int temp = dp[j];

                if (s[i - 1] == p[j - 1] || p[j - 1] == '.')
                {
                    dp[j] = prev;
                }
                else if (p[j - 1] != '*')
                {
                    dp[j] = false;
                }
                else if (p[j - 2] == '.' || p[j - 2] == s[i - 1])
                {
                    dp[j] = dp[j] || dp[j - 2];
                }
                else
                {
                    dp[j] = dp[j - 2];
                }

                prev = temp;
            }
        }

        return dp[n];
    }
};
