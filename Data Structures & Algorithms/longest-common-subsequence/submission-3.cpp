class Solution {
public:
    // Time complexity: O(mn); Space complexity: O(n); used 2 1-D arrays.
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.size(), n = text2.size();
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= m; i++)
        {
            vector<int> prev = dp;
            for (int j = 1; j <= n; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[j] = 1 + prev[j - 1];
                }
                else
                {
                    dp[j] = max(prev[j], dp[j - 1]);
                }
            }
        }

        return dp[n];
    }
};
