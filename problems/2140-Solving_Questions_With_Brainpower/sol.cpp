/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/solving-questions-with-brainpower
 * Runtime: 7 ms (54.53%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> mem(questions.size(), -1);

        auto dfs = [&](this auto const& self, int idx) -> long long {
                if (idx >= questions.size())
                    return 0;

                if (mem[idx] != -1)
                    return mem[idx];

                return mem[idx] = max(self(idx + 1), self(idx + questions[idx][1] + 1) + questions[idx][0]);
            };

        return dfs(0);
    }
};
