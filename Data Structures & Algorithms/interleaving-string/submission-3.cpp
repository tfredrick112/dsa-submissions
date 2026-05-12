class Solution {
public:
    // Time complexity: O(m*n) where m is s1.size() and n is s2.size()
    // Space complexity: O(m * n)
    bool f(string& s1, string& s2, string& s3, int i, int j, vector<vector<int>>& dp)
    {
        int k = i + j;
        if (i == s1.size())
            return s2.substr(j) == s3.substr(k);

        if (j == s2.size())
            return s1.substr(i) == s3.substr(k);

        if (dp[i][j] != -1)
            return dp[i][j] == 1;

        if (s1[i]==s3[k] && s2[j]==s3[k])
        {
            return dp[i][j] = f(s1, s2, s3, i + 1, j, dp) || f(s1, s2, s3, i, j + 1, dp);
        }
        else if (s1[i] == s3[k])
        {
            return dp[i][j] = f(s1, s2, s3, i + 1, j, dp);
        }
        else if (s2[j]==s3[k])
        {
            return dp[i][j] = f(s1, s2, s3, i, j + 1, dp);
        }
        else
        {
            return dp[i][j] = false;
        }
    }
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.size() + s2.size() != s3.size())
            return false;

        int m = s1.size(), n = s2.size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return f(s1, s2, s3, 0, 0, dp);
    }
};
