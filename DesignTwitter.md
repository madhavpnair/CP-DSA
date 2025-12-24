# LeetCode 355 — Design Twitter

We are asked to implement four methods in the `Twitter` class<br>

---

## Design Overview

The following key data structures are used:

1. Maintain a global `time counter` to keep track of the recency of tweets
2. Treat each tweet as a `pair (tweetId, time)`
3. `priority_queue` for each user which acts as the complete tweet history of the user where `time` is the key
4. `vector` for each user to maintain the list of her followers
5. `vector` for each user to maintain the list of her followees

## Methods

### `postTweet`
- Increment the global time counter
- Simply push this tweet to her tweet history
---
### `getNewsFeed`
- All the posts of the user and all her followees' constitute her complete feed `allTweets`
- Display the top 10 posts from the user's complete feed based on recency
---
### `follow`
- Beware of duplicates<br>
- Add the followerId to the followers list of the followeeId iff she is not a follower<br>
- Add the followeeId to the followees list of the followerId iff she is not a followee<br>
---
### `unfollow`
- Beware of underflow<br>
- Remove the followerId from the followers list of the followeeId iff she is a follower<br>
- Remove the followeeId from the followees list of the followerId iff she is a followee<br>
