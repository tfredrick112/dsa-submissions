class Solution {
public:
    // This is a O(n + maxWt) solution. Using a persistent j variable and NOT starting from
    // i - 1 each time ensures that we don't scan through zero values unnecessarily for 
    // every iteration of the outer loop.

    // Note: building the buckets array is O(n + maxWt). Although we are updating only n buckets
    // in the for loop, we are initializing maxWt + 1 elements with 0s. That is why building buckets
    // costs O(n + maxWt).
    int lastStoneWeight(vector<int>& stones)
    {
        int maxWt = *max_element(stones.begin(), stones.end());
        vector<int> buckets(maxWt + 1, 0);

        for (int& num : stones)
        {
            buckets[num]++;
        }

        int j = maxWt;

        for (int i = maxWt; i >= 0; i--)
        {
            if (buckets[i] % 2 == 0)
            {
                buckets[i] = 0;
            }
            else
            {
                buckets[i] = 1;

                // This is to have a persistent j. We don't want to scan from i - 1 each time
                j = min(i - 1, j);
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
