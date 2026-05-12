class Solution {
public:
    void changeHelper(vector<int>& coins, int amount, int idx, int& count)
    {
        if (amount == 0)
        {
            count++;
            return;
        }
        else if (amount < 0)
        {
            return;
        }
        
        for (int i = idx; i < coins.size(); i++)
        {
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
