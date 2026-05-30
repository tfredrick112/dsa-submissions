class Solution {
public:
    int lastStoneWeight(vector<int>& stones)
    {
        int maxWt = *max_element(stones.begin(), stones.end());
        vector<int> buckets(maxWt + 1, 0);

        for (int& num : stones)
        {
            buckets[num]++;
        }

        for (int i = maxWt; i >= 0; i--)
        {
            if (buckets[i] % 2 == 0)
            {
                buckets[i] = 0;
            }
            else
            {
                buckets[i] = 1;

                int j = i - 1;
                while (j >= 0 && buckets[j] == 0)
                {
                    j--;
                }

                if (j >= 0)
                {
                    buckets[i] = 0;
                    buckets[j]--;
                    buckets[i - j]++;
                }
                else
                {
                    return i;
                }
            }
        }

        for (int i = 0; i <= maxWt; i++)
        {
            if (buckets[i] == 1)
            {
                return i;
            }
        }

        return 0;
    }
};
