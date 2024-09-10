class Twitter {
    int count;
    unordered_map<int, vector<pair<int, int>>> posts;
    unordered_map<int, unordered_set<int>> following;
    
public:
    Twitter() {
        count = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({tweetId, count++});
    }
    
    vector<int> getNewsFeed(int userId) {
        follow(userId, userId);
        vector<int> res;
        unordered_map<int, int> curr_idx;
        for (int user : following[userId]) {
            curr_idx[user] = posts[user].size() - 1;
        }

        for (int i = 0; i < 10; i++) {
            int recent_user = -1;
            for (int user : following[userId]) {
                if(curr_idx[user] < 0) continue;
                if (recent_user == -1 || posts[user][curr_idx[user]].second > posts[recent_user][curr_idx[recent_user]].second) {
                    recent_user = user;
                }
            }
            if (recent_user == -1) break;
            res.push_back(posts[recent_user][curr_idx[recent_user]].first);
            curr_idx[recent_user]--;
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */