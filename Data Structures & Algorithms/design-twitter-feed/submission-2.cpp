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
    
    // O(10Flog10F) which can be simplified to O(FlogF)
    vector<int> getNewsFeed(int userId)
    {
        vector<pair<int, int>> tweetsWithTime;

        // fetch the latest 10 tweets of each followee
        for (const auto& followeeId : followees[userId])
        {
            int numTweets = userToTweets[followeeId].size();

            for (int i = 1; i <= 10 && i <= numTweets; i++)
            {
                tweetsWithTime.push_back(userToTweets[followeeId][numTweets - i]);
            }
        }

        // to ensure that the userId was not already included in the list of followees
        if (followees[userId].count(userId) == 0)
        {
            // we have to consider the latest 10 tweets posted by userId themselves too
            int numSelfTweets = userToTweets[userId].size();
            for (int k = 1; k <= 10 && k <= numSelfTweets; k++)
            {
                tweetsWithTime.push_back(userToTweets[userId][numSelfTweets - k]);
            }
        }

        auto cmp = [](const auto& a, const auto& b){
            return a.second > b.second;
        };

        sort(tweetsWithTime.begin(), tweetsWithTime.end(), cmp);

        vector<int> result;

        for (int j = 0; j < 10 && j < tweetsWithTime.size(); j++)
        {
            result.push_back(tweetsWithTime[j].first);
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
