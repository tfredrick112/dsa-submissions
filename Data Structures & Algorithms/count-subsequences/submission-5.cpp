class Solution {
public:
    // Time complexity = O(mn), space complexity = O(n)
    int numDistinct(string s, string t)
    {
        int m = s.size(), n = t.size();
        if (m < n)
            return 0;
        
        vector<unsigned long long> dp(n + 1, 0);

        dp[0] = 1;

        // dp[0][j] should be 0 for j = 1 to j = n => there are no characters in s, so we cannot
        // get a subsequence of non-zero length from it.
        // this is already handled during initialization.

        for (int i = 1; i <= m; i++)
        {
            int prev = dp[0];

            for (int j = 1; j <= n; j++)
            {
                int temp = dp[j];

                if (s[i - 1] == t[j - 1])
                {
                    dp[j] = prev + dp[j];
                }
                else
                {
                    dp[j] = dp[j];
                }

                prev = temp;
            }
        }

        return dp[n];
    }
};
