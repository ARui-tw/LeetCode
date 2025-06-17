/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/task-scheduler
 * Runtime: 22 ms (49.06%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int, int>> ready;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> cooling;
        vector<int> vec(26, 0);

        for (auto& c : tasks) {
            vec[c - 'A']++;
        }

        for (int i = 0; i < 26; i++) {
            if (vec[i])
                ready.push({vec[i], i});
        }

        int res = 0;
        while (true) {
            if (ready.empty() && cooling.empty()) return res;

            res++;

            while (!cooling.empty()) {
                auto [time, task] = cooling.top();
                if (time < res) {
                    ready.push({vec[task], task});
                    cooling.pop();
                } else break;
            }

            if (ready.empty()) {
                continue;
            }

            auto [cnt, task] = ready.top();
            ready.pop();
            vec[task]--;
            if (vec[task]) {
                cooling.push({res + n, task});
            }
        }

        return res;
    }
};
