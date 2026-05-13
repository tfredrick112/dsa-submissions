class Solution {
public:
    int insertCost = 1;
    int deleteCost = 1;
    int replaceCost = 1;
    int editDistance(string& s1, int m, string& s2, int n)
    {
        if (m == 0)
            return n * insertCost;

        if (n == 0)
            return m * deleteCost;

        int replacementCost = s1[m - 1] == s2[n - 1] ? 0 : replaceCost;

        return min(
            {
                editDistance(s1, m - 1, s2, n - 1) + replacementCost,
                editDistance(s1, m - 1, s2, n) + deleteCost,
                editDistance(s1, m, s2, n - 1) + insertCost
            }
        );
    }
    int minDistance(string word1, string word2)
    {
        int m = word1.size(), n = word2.size();
        return editDistance(word1, m, word2, n);
    }
};
