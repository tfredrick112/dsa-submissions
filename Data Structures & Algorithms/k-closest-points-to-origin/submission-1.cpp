class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](pair<vector<int>, double>& x, pair<vector<int>, double>& y){
            return x.second < y.second;
        };

        priority_queue<pair<vector<int>, double>, vector<pair<vector<int>, double>>, decltype(cmp)> pq;

        for (int i = 0; i < points.size() ; i++)
        {
            double dist = sqrt(pow(points[i][0], 2) + pow(points[i][1], 2));
            pq.push({points[i], dist});

            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        vector<vector<int>> resultPoints;
        while(!pq.empty())
        {
            resultPoints.push_back(pq.top().first);
            pq.pop();
        }

        return resultPoints;

    }
};
