class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {
        mp.clear();
    }
    
    void set(string key, string value, int timestamp)
    {
        // if (mp.count(key) > 0)
        // {
        //     mp[key].push_back({timestamp, value});
        // }
        // else
        // {
        //     mp[key] = vector<pair<int, string>>({make_pair(timestamp, value)});
        // }

        mp[key].push_back({timestamp, value});
    }

    int findInsertionIndex(vector<pair<int, string>>& values, int timestamp)
    {
        int l = 0, r = values.size() - 1;
        while (l <= r)
        {
            int mid = l + (r - l)/2;
            if (values[mid].first == timestamp)
            {
                return mid;
            }
            else if (values[mid].first > timestamp)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return l;
    }
    
    string get(string key, int timestamp)
    {
        if (mp.count(key) == 0)
            return "";

        vector<pair<int, string>>& values = mp[key];
        int index = findInsertionIndex(values, timestamp);

        if (index > values.size() - 1)
        {
            return values[values.size() - 1].second;
        }

        if (values[index].first == timestamp)
        {
            return values[index].second;
        }
        else
        {
            // the exact timestamp was not found, we have to return the value from index - 1
            if (index == 0)
                return "";
            else
                return values[index - 1].second;
        }

        // dead code
        return "";
    }
};
