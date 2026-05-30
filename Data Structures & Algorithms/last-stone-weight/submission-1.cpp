class Solution {
public:
    // Time complexity = O(n log n) : A push / pop operation takes O(log n) time for a max heap. Space complexity = O(n)
    int lastStoneWeight(vector<int>& stones)
    {
        priority_queue<int> pq;

        for (int& num : stones)
        {
            pq.push(num);
        }

        while (pq.size() > 1)
        {
            int x = pq.top();
            pq.pop();

            int y = pq.top();
            pq.pop();

            if (x == y)
            {
                continue;
            }

            pq.push(x - y);
        }

        if (pq.size() == 1)
            return pq.top();
        else
            return 0;
    }
};
