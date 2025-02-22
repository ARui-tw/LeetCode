/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/course-schedule-ii
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> need(numCourses, 0);
        vector<vector<int>> needed(numCourses, vector<int>());
        queue<int> qu;
        vector<int> res;

        for (auto pre : prerequisites) {
            need[pre[0]]++;
            needed[pre[1]].push_back(pre[0]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (need[i] == 0) qu.push(i);
        }

        while (!qu.empty()) {
            int cur = qu.front();
            qu.pop();

            for (auto n : needed[cur]) {
                need[n]--;
                if (need[n] == 0) qu.push(n);
            }
            res.push_back(cur);
        }

        if (res.size() < numCourses) return vector<int>();

        return res;
    }
};
