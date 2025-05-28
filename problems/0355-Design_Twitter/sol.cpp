/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/design-twitter
 * Runtime: 0 ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Twitter {
    // unordered_map<int, unordered_set<int>> following;
    unordered_map<int, unordered_set<int>> followed;
    unordered_map<int, vector<pair<int, int>>> timeline;
    unordered_map<int, vector<pair<int, int>>> posts;
    int counter;

public:
    Twitter() {
        counter = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        timeline[userId].push_back({tweetId, counter});
        posts[userId].push_back({tweetId, counter});
        for (auto &f : followed[userId]) {
            timeline[f].push_back({tweetId, counter});
        }
        counter++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        int n = timeline[userId].size() - 1;
        for (int i = n; i > n - 10 && i >= 0; i--) {
            res.push_back(timeline[userId][i].first);
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if (followed[followeeId].count(followerId)) {
            return;
        }
        followed[followeeId].insert(followerId);
        vector<pair<int, int>> tmp(timeline[followerId].begin(), timeline[followerId].end());
        timeline[followerId].clear();
        int a = tmp.size() - 1;
        int b = posts[followeeId].size() - 1;
        while (a >= 0 || b >=0) {
            if (b < 0) {
                timeline[followerId].push_back(tmp[a]);
                a--;
                continue;
            } else if (a < 0) {
                timeline[followerId].push_back(posts[followeeId][b]);
                b--;
                continue;
            }
            if (tmp[a].second > posts[followeeId][b].second) {
                timeline[followerId].push_back(tmp[a]);
                a--;
            } else {
                timeline[followerId].push_back(posts[followeeId][b]);
                b--;
            }
        }
        reverse(timeline[followerId].begin(), timeline[followerId].end());
    }
    
    void unfollow(int followerId, int followeeId) {
        followed[followeeId].erase(followerId);
        int cnt = 0, p1 = timeline[followerId].size() - 1, p2 = posts[followeeId].size() - 1;
        while (cnt < 10) {
            if (p1 < 0 || p2 < 0) {
                break;
            }
            if (timeline[followerId][p1].first == posts[followeeId][p2].first) {
                timeline[followerId].erase(timeline[followerId].begin() + p1);
                p1--;
                p2--;
            } else {
                cnt++;
                p1--;
            }
        }
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
