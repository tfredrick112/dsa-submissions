class Solution {
public:
    bool isRateSufficient(vector<int>& piles, int h, int k)
    {
        long int timeTaken = 0;

        for(int i = 0; i < piles.size(); i++)
        {
            timeTaken += (piles[i] / k) + (piles[i] % k == 0 ? 0 : 1);
        }

        return timeTaken <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxBananas = *max_element(piles.begin(), piles.end());
        
        int left = 1, right = maxBananas;
        int minK = maxBananas;

        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(isRateSufficient(piles, h, mid))
            {
                minK = min(minK, mid); // mid was enough, now we check if a lower rate
                // is sufficent

                right = mid - 1;
            }
            else
            {
                // the rate was not enough, so we need to search among the higher values
                left = mid + 1;
            }
        }

        return minK;
    }
};
