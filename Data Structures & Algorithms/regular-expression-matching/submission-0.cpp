class Solution {
public:
    // Time complexity: 2 ^ (m + n); Space complexity: O(m + n)
    bool f(string& s, string& p, int m, int n)
    {
        if (n == 0)
            return m == 0;

        if (m == 0)
        {
            if (p[n - 1] != '*')
                return false;
            else
                return f(s, p, m, n - 2);
        }

        if (p[n - 1] == '.' || p[n - 1] == s[m - 1])
            return f(s, p, m - 1, n - 1);

        if (p[n - 1] != '*')
            return false;

        if (p[n - 2] == '.' || p[n - 2] == s[m - 1])
            return f(s, p, m - 1, n) || f(s, p, m, n - 2);
        else
            return f(s, p, m, n - 2);
    }
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();
        return f(s, p, m, n);
    }
};
