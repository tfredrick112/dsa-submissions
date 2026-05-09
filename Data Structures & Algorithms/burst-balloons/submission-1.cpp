class Solution {
public:
    int maxCoins(vector<int>& nums)
    {
        // pad the input with 1 at the beginning and end
        vector<int> padded;
        padded.push_back(1);
        copy(nums.begin(), nums.end(), std::back_inserter(padded));
        padded.push_back(1);

        int n = padded.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        //dp[l][r] is the max points earned by bursting all the balloons BETWEEN l and r.
        //If l==r or l + 1 == r, then there are no balloons between l and r
        //So, dp[l][r] = 0 if l == r or if l + 1 == r.

        for (int i = 0; i < n; i++)
        {
            dp[i][i] = 0;
        }

        for (int i = 0; i < n - 1; i++)
        {
            dp[i][i + 1] = 0;
        }

        for (int i = 0; i < n - 2; i++)
        {
            dp[i][i + 2] = padded[i] * padded[i + 1] * padded[i + 2];
        }

        for (int len = 4; len <= n; len++)
        {
            for (int l = 0; l <= n - len; l++)
            {
                int r = l + len - 1;
                for (int k = l + 1; k < r; k++)
                {
                    dp[l][r] = max(dp[l][r], dp[l][k] + dp[k][r] + padded[l] * padded[k] * padded[r]);
                }
            }
        }

        return dp[0][n - 1];
    }
};
