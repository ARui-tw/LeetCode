/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/maximum-profit-in-job-scheduling
 * Runtime: 27 ms (89.21%)
 */

class Solution {
    struct Job {
        int s;
        int e;
        int p;
    };
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<int> dp(n, -1);
        vector<Job> jobs;
        jobs.reserve(n);
        int res = -1;

        for (int i = 0; i < n; i++) {
            jobs.push_back(Job({startTime[i], endTime[i], profit[i]}));
        }

        sort(jobs.begin(), jobs.end(), [](const auto& lhs, const auto& rhs) {
            return lhs.s < rhs.s;
        });

        for (int i = n - 1; i >= 0; i--) {
            Job dummy({jobs[i].e, 0, 0});

            auto next = lower_bound(jobs.begin(), jobs.end(), dummy, [](const auto& lhs, const auto& rhs) {
                return lhs.s < rhs.s;
            });

            int nxt = next - jobs.begin();

            dp[i] = max((i + 1 >= n ? 0 : dp[i+1]), jobs[i].p + (nxt >= n ? 0 : dp[nxt]));
        }

        return dp[0];
    }
};
