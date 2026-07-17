class Twitter {
public:
    unordered_map<int,unordered_set<int>> mp;
    stack<pair<int,int>> posts;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        posts.push({userId,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        int count=10;
        stack<pair<int,int>> temp;
        while(count!=0&&posts.size()>0){
            auto& x=posts.top();
            temp.push(posts.top());
            posts.pop();
            if(mp[userId].contains(x.first)||x.first==userId){
                feed.push_back(x.second);
                count--;
            }
        }
        while(!temp.empty()){
            posts.push(temp.top());
            temp.pop();
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        mp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        mp[followerId].erase(followeeId);
    }
};
