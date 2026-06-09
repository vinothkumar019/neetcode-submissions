class Twitter {
public:

    int timer;
    unordered_map<int, unordered_set<int>> followMap;
    unordered_map<int, vector<pair<int,int>>> tweetMap;

    Twitter() {
        timer = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push_back({timer++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {

        priority_queue<pair<int,int>> pq;

        // User's own tweets
        for(auto& tweet : tweetMap[userId]) {
            pq.push(tweet);
        }

        // Followees' tweets
        for(auto followee : followMap[userId]) {
            for(auto& tweet : tweetMap[followee]) {
                pq.push(tweet);
            }
        }

        vector<int> res;

        while(!pq.empty() && res.size() < 10) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }

    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return;
        followMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};