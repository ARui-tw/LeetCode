/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/task-scheduler
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int ma = -1, maCnt = 0;
        vector<int> vec(26, 0);

        for (auto& task : tasks) {
            int& v = vec[task - 'A'];
            v++;
            if (v > ma) {
                ma = v;
                maCnt = 1;
            } else if (v >= ma) {
                maCnt++;
            }
        }

        return max((int)tasks.size(), (n + 1) * (ma - 1) + (maCnt));
    }
};
