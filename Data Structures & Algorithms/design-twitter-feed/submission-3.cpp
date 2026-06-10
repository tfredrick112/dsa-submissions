class Twitter {
public:
    int time;
    unordered_map<int, vector<pair<int, int>>> userToTweets;
    unordered_map<int, unordered_set<int>> followees;

    Twitter()
    {
        time = 0;
        userToTweets.clear();
        followees.clear();
    }
    
    void postTweet(int userId, int tweetId) {
        time++;
        userToTweets[userId].push_back({tweetId, time});
    }
    
    // O(F log F) time to insert F elements into the max heap.
    // Extraction time - only O(10 log F)
    // This way, we avoid taking 10 latest tweets from each of the F followees and sorting the 10F tweets in descending order.
    // Just insert the latest tweet of each followee, pop out the latest of all such tweets and then push the previous tweet of that followee into the max heap.
    vector<int> getNewsFeed(int userId)
    {
        auto cmp = [](const auto& x, const auto& y){
            return x[2] < y[2];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq;

        for (int followee : followees[userId])
        {
            int numTweets = userToTweets[followee].size();
            if (numTweets > 0)
                pq.push({followee, numTweets - 1, userToTweets[followee][numTweets - 1].second});
        }

        if (followees[userId].count(userId) == 0)
        {
            int numTweets = userToTweets[userId].size();
            if (numTweets > 0)
                pq.push({userId, numTweets - 1, userToTweets[userId][numTweets - 1].second});
        }

        vector<int> result;

        while(!pq.empty() && result.size() < 10)
        {
            vector<int> curr = pq.top();
            pq.pop();

            int id = curr[0], index = curr[1];

            result.push_back(userToTweets[id][index].first);

            if (index > 0)
            {
                pq.push({id, index - 1, userToTweets[id][index - 1].second});
            }
        }

        return result;
    }
    
    void follow(int followerId, int followeeId)
    {
        followees[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId)
    {
        followees[followerId].erase(followeeId);
    }
};
