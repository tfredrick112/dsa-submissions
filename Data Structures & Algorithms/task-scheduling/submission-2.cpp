class Solution {
public:
    int leastInterval(vector<char>& tasks, int n)
    {
        int total = tasks.size();

        auto cmp = [](const auto& a, const auto& b){
            return a.second < b.second;
        };
        
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq;

        queue<pair<char, int>> cdq;

        unordered_map<char, int> freq;
        for (char& ch : tasks)
        {
            freq[ch]++;
        }

        for(const auto& [k, v] : freq)
        {
            pq.push({k, v});
        }

        int count = 0;
        int time = 0;

        while (count < total)
        {
            time++;

            while(!cdq.empty() && cdq.front().second <= time)
            {
                char ch = cdq.front().first;
                cdq.pop();
                pq.push({ch, freq[ch]});
            }

            if (pq.empty())
                continue;

            auto [task, remCount] = pq.top();
            pq.pop();

            freq[task] = remCount - 1;
            count++;
            
            if (freq[task] > 0)
                cdq.push({task, time + n + 1});
        }

        return time;
    }
};
