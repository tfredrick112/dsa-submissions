class Solution {
public:
    // Recursive solution - exponential time complexity
    int numDistinctWays(string& s, string& t, int m, int n)
    {
        if (n == 0)
            return 1;
        
        if (m < n)
            return 0;

        if (s[m - 1] == t[n - 1])
        {
            return numDistinctWays(s, t, m - 1, n - 1) + numDistinctWays(s, t, m - 1, n);
        }
        else
        {
            return numDistinctWays(s, t, m - 1, n);
        }
    }

    int numDistinct(string s, string t)
    {
        int m = s.size(), n = t.size();
        return numDistinctWays(s, t, m, n);
    }
};
