#include <bits/stdc++.h>
using namespace std;
class Twitter {


public:


    int time = 0;
    
    vector<priority_queue<pair<int,int>>>v; //complete tweet history of each user
    vector<vector<int>>followers; //followers of each user
    vector<vector<int>>following; //others followed by each user


    Twitter() {
        v.resize(500);
        followers.resize(500);
        following.resize(500);
        cout<<"twitter instantiated\n";
    }
    
    void postTweet(int userId, int tweetId) {
        
        time++;
        v[userId].push({time, tweetId});

    }
    
    vector<int> getNewsFeed(int userId) {

        
        vector<int>res(0);
        priority_queue<pair<int,int>>allTweets;      //all tweets in the feed of the user userId
        vector<priority_queue<pair<int,int>>>copies; //copy of the complete tweet history of each user
        copies.resize(500);


        for(auto followee: following[userId]){
            copies[followee] = v[followee];
            while(!copies[followee].empty()){
                allTweets.push(copies[followee].top());
                copies[followee].pop();
            }
        }
        
        copies[userId] = v[userId];

        while(!copies[userId].empty()){
            allTweets.push(copies[userId].top());
            copies[userId].pop();
        }

        //pick the most recent 10 or available posts
        while(res.size()<10 && !allTweets.empty()){
            int recent_tweet = allTweets.top().second;
            allTweets.pop();
            if(find(res.begin(), res.end(), recent_tweet)==res.end())
                res.push_back(recent_tweet);
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        //add the followerId to the followers of the followeeId "if not present"
        auto it = find(followers[followeeId].begin(), followers[followeeId].end(), followerId);
        if(it == followers[followeeId].end())
            followers[followeeId].push_back(followerId);

        //add the followeeId to the followees of the followerId "if not present"
        auto it_ = find(following[followerId].begin(), following[followerId].end(), followeeId);
        if(it_ == following[followerId].end())
            following[followerId].push_back(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        //remove from both the lists "if present"
        auto it = find(followers[followeeId].begin(), followers[followeeId].end(), followerId);
        if(it!=followers[followeeId].end())
            followers[followeeId].erase(it);

        auto it_ = find(following[followerId].begin(), following[followerId].end(), followeeId);
        if(it_!=following[followerId].end())
            following[followerId].erase(it_);

    }
    

};
