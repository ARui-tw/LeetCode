/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> point;
        int n = startTime.size();
        point.reserve(n+2);

        point.push_back(startTime[0]);
        for (int i = 0; i < n-1; i++) {
            point.push_back(startTime[i+1] - endTime[i]);
        }
        point.push_back(eventTime - endTime[n-1]);

        int i = 0;
        int res = 0;
        int cur = 0;
        for (; i < k; i++) {
            cur += point[i];
        }
        for (; i < point.size(); i++) {
            cur += point[i];
            res = max(res, cur);
            cur -= point[i-k];
        }


        return res;
    }
};
