class Solution {
public:
    string minWindow(string s, string t)
    {
        int m = s.size(), n = t.size();
        if (m < n)
            return "";

        int count = 0, start = 0, startIndex = -1, minLen = INT_MAX;
        vector<int> freqT(128, 0);
        vector<int> freqS(128, 0);

        for (char ch : t)
        {
            freqT[ch]++;
        }

        for (int i = 0; i < m; i++)
        {
            freqS[s[i]]++;

            if (freqT[s[i]] != 0 && freqS[s[i]] <= freqT[s[i]])
            {
                count++;
            }

            if (count == n)
            {
                // shrinking the window from the front if the character at the front
                // is either not present in t, or if the number of occurrences of the
                // character in the current window is greater than the number of
                // occurrences in t.
                while (freqT[s[start]] == 0 || freqS[s[start]] > freqT[s[start]])
                {
                    freqS[s[start]]--;
                    start++;
                }

                int currLen = i - start + 1;
                if (minLen > currLen)
                {
                    minLen = currLen;
                    startIndex = start;
                }
            }
        }

        if (startIndex == -1)
            return "";
        else
            return s.substr(startIndex, minLen);
    }
};
