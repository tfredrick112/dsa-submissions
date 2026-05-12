class Solution {
public:
    // Exponential time complexity
    bool f(string& s1, string& s2, string& s3, int i, int j)
    {
        int k = i + j;
        if (i == s1.size())
        {
            return s2.substr(j) == s3.substr(k);
        }

        if (j == s2.size())
        {
            return s1.substr(i) == s3.substr(k);
        }

        if (s1[i]==s3[k] && s2[j] == s3[k])
        {
            // Here there are two options, we can either use the match from s1 or s2,
            // so we need to consider both.
            return f(s1, s2, s3, i + 1, j) || f(s1, s2, s3, i, j + 1);
        }
        else if (s1[i]==s3[k])
        {
            return f(s1, s2, s3, i + 1, j);
        }
        else if (s2[j] == s3[k])
        {
            return f(s1, s2, s3, i, j + 1);
        }
        else
        {
            return false;
        }
    }
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;

        return f(s1, s2, s3, 0, 0);
    }
};
