class CountSquares {
public:
    unordered_map<int, unordered_map<int, int>> hashMap;
    CountSquares()
    {
        hashMap = unordered_map<int, unordered_map<int, int>>();
    }
    
    // O(1) time complexity
    void add(vector<int> point)
    {
        int x = point[0], y = point[1];
        hashMap[x][y]++;
    }

    // O(1) time complexity
    int pointCountLookup(vector<int>& point)
    {
        if (hashMap.count(point[0]) > 0 && hashMap[point[0]].count(point[1]) > 0)
        {
            return hashMap[point[0]][point[1]];
        }

        return 0;
    }
    
    // O(N) where N is the number of entries in the nested unordered_map corresponding to the x-coordinate of the query point.
    int count(vector<int> point)
    {
        int x1 = point[0], y1 = point[1];

        if (hashMap.count(x1) == 0)
            return 0;

        int result = 0;

        vector<int> pt2, pt3, pt4;

        for(const auto& [y2, count2] : hashMap[x1])
        {
            int side = abs(y1 - y2);
            if (side == 0)
                continue;

            pt2 = {x1, y2};
            pt3 = {x1 + side, y1};
            pt4 = {x1 + side, y2};

            result += count2 * pointCountLookup(pt3) * pointCountLookup(pt4);

            pt3 = {x1 - side, y1};
            pt4 = {x1 - side, y2};

            result += count2 * pointCountLookup(pt3) * pointCountLookup(pt4);
        }

        return result;
    }
};
