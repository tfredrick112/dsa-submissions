class Solution {
public:
    int insertCost = 1;
    int deleteCost = 1;
    int replaceCost = 1;

    // Time complexity after memoization - O(m * n)
    // Space complexity O(m * n)
    int editDistance(string& s1, int m, string& s2, int n, vector<vector<int>>& dp)
    {
        if (m == 0)
            return n * insertCost;

        if (n == 0)
            return m * deleteCost;

        if (dp[m][n] != -1)
            return dp[m][n];

        int replacementCost = s1[m - 1] == s2[n - 1] ? 0 : replaceCost;

        return dp[m][n] = min(
            {
                editDistance(s1, m - 1, s2, n - 1, dp) + replacementCost,
                editDistance(s1, m - 1, s2, n, dp) + deleteCost,
                editDistance(s1, m, s2, n - 1, dp) + insertCost
            }
        );
    }
    int minDistance(string word1, string word2)
    {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return editDistance(word1, m, word2, n, dp);
    }
};
