/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended
 * Runtime: 57 ms (84.03%)
 */

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pending;
        priority_queue<int, vector<int>, greater<int>> running;

        for (auto& e : events) {
            pending.push({e[0], e[1]});
        }

        int curDay = 1;
        int res = 0;
        while (!running.empty() || !pending.empty()) {
            while (!pending.empty() && pending.top().first <= curDay) {
                auto [start, end] = pending.top();
                pending.pop();
                running.push(end);
            }

            while (!running.empty() && running.top() < curDay) {
                running.pop();
            }

            if (!running.empty()) {
                running.pop();
                res++;
            }

            if (running.empty() && !pending.empty()) {
                curDay = pending.top().first - 1;
            }

            curDay++;
        }
        
        return res;
    }
};
