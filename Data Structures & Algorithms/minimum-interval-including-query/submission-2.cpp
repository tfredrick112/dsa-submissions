class Solution {
public:
    // Time complexity = O(n log n + q log q)
    // Space complexity = O(n + q)
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries)
    {
        int n = intervals.size();

        // sort the intervals in ascending order of the start times
        sort(intervals.begin(), intervals.end());

        // copy the queries into another vector and sort in ascending order
        vector<int> sortedQueries = queries;
        sort(sortedQueries.begin(), sortedQueries.end());

        // minHeap contains {interval size, interval end}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

        unordered_map<int, int> resultMap;

        int i = 0;

        for (int j = 0; j < sortedQueries.size(); j++)
        {
            // push valid intervals into the minHeap
            while (i < n && sortedQueries[j] >= intervals[i][0])
            {
                if (sortedQueries[j] >= intervals[i][0] && sortedQueries[j] <= intervals[i][1])
                {
                    minHeap.push({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
                }

                i++;
            }

            while (!minHeap.empty() && minHeap.top().second < sortedQueries[j])
            {
                // lazily remove the expired intervals
                minHeap.pop();
            }

            if (minHeap.empty())
            {
                resultMap[sortedQueries[j]] = -1;
            }
            else
            {
                resultMap[sortedQueries[j]] = minHeap.top().first;
            }
        }

        vector<int> result;

        for (int q : queries)
        {
            result.push_back(resultMap[q]);
        }

        return result;
    }
};
