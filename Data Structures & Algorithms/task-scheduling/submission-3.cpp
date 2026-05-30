class Solution {
public:
    int leastInterval(vector<char>& tasks, int n)
    {
        unordered_map<char, int> freq;
        for (char& ch : tasks)
            freq[ch]++;

        int maxf = -1;
        for(const auto& [k, v] : freq)
        {
            maxf = max(maxf, v);
        }

        int maxCount = 0;
        for (const auto& [k, v] : freq)
        {
            if (maxf == v)
                maxCount++;
        }

        int total = tasks.size();

        return max(total, (maxf - 1) * (n + 1) + maxCount);
    }
};
