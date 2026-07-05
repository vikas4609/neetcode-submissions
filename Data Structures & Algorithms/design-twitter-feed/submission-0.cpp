class Twitter {
    int count;
    unordered_map<int, vector<vector<int>>> tweetmap;
    unordered_map<int, unordered_set<int>> followmap;

public:
    Twitter() {
        count = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetmap[userId].push_back({count++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        followmap[userId].insert(userId);
        priority_queue<vector<int>, vector<vector<int>>, decltype([](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        })> minHeap;
        for(int f : followmap[userId]){
            if(tweetmap.count(f)){
                vector<vector<int>> vec = tweetmap[f];
                int idx = vec.size()-1;
                minHeap.push({vec[idx][0],vec[idx][1],f,idx});
            }
        }
        while(!minHeap.empty() && res.size() < 10){
            vector<int> curr = minHeap.top();
            minHeap.pop();
            res.push_back(curr[1]);
            int index = curr[3]-1;
            if(index >= 0){
                vector<vector<int>> vec = tweetmap[curr[2]];
                minHeap.push({vec[index][0],vec[index][1],curr[2],index});
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followmap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followmap[followerId].erase(followeeId);
    }
};
