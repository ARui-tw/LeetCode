/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/permutations
 * Runtime: 0 ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        auto backtrack = [&](this const auto& self, int idx)->void {
            if (idx == nums.size()) {
                res.push_back(nums);
                return;
            }

            for (int i = idx; i < nums.size(); i++) {
                swap(nums[i], nums[idx]);
                self(idx + 1);
                swap(nums[i], nums[idx]);
            }
        };

        backtrack(0);

        return res;
    }
};
