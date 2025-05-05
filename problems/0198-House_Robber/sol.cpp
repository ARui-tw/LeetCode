/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/house-robber
 * Runtime: 0 ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<vector<int>> mem(nums.size(), vector<int>(2, -1));

        auto dfs = [&](this const auto& self, int pos, bool canSteal) -> int {
            if (pos == nums.size()) return 0;

            if (mem[pos][canSteal] != -1) return mem[pos][canSteal];

            if (!canSteal) {
                return mem[pos][canSteal] = self(pos + 1, true);
            } else {
                return mem[pos][canSteal] = max(self(pos + 1, true), self(pos + 1, false) + nums[pos]);
            }
        };

        return dfs(0, true);
    }

};
