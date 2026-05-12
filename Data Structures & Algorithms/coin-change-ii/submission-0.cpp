class Solution {
public:
    // This solution will have exponential time complexity
    // It explores all possible paths and increments the count by 1 when a
    // sum == amount is found.

    void changeHelper(vector<int>& coins, int amount, int idx, int& count)
    {
        if (amount == 0)
        {
            count++; // The amount has become 0, which means we have found 1 valid way to get the required sum.
            return;
        }
        else if (amount < 0)
        {
            return;
        }
        
        for (int i = idx; i < coins.size(); i++)
        {
            // This loop starts from idx and not from 0, because we want to avoid duplicate solutions.
            // i.e. 1 + 3 = 4 and 3 + 1 = 4, so if we make sure that we only look ahead in the coins array.
            // we will only count [1, 3] and we will not count [3,1] which will simply be a duplicate.

            // Why are we sending i for the idx parameter? Because we have an unlimited supply of each coin
            // We can use coins[i] and still use it again in the next step. If we sent i + 1, it means that we are
            // not reusing a coin.
            changeHelper(coins, amount - coins[i], i, count);
        }
    }
    int change(int amount, vector<int>& coins)
    {
        int count = 0;
        changeHelper(coins, amount, 0, count);
        return count;
    }
};
