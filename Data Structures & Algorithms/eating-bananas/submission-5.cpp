class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h)
    {
        int n = piles.size();

        // There is no point in eating faster than the number of bananas in the largest pile.
        // Because, if speed = k, and a pile has less than k bananas, Koko cannot finish this pile and then go eat from another pile in the same hour.
        int maxEatingSpeed = *max_element(piles.begin(), piles.end());

        int left = 1, right = maxEatingSpeed;
        int minEatingSpeed = maxEatingSpeed;

        while (left <= right)
        {
            int speed = left + (right - left) / 2;

            long numHours = 0;
            for (int i = 0; i < n; i++)
            {
                numHours += piles[i]/speed + (piles[i] % speed == 0 ? 0 : 1);
            }

            if (numHours > h)
            {
                // current speed is not enough, look for a higher value
                left = speed + 1;
            }
            else if (numHours <= h)
            {
                // this is fast enough, so we store it but check if we can find a slower speed
                // that satisfies the condition
                minEatingSpeed = min(minEatingSpeed, speed);

                right = speed - 1;
            }
        }

        return minEatingSpeed;
    }
};
