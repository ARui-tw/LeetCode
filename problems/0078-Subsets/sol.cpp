/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/subsets
 * Runtime: 0 ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        res.reserve(pow(2, n));
        res.push_back(vector<int>());

        for (auto &num : nums) {
            vector<vector<int>> cur(res.begin(), res.end());
            for (auto& c : cur) c.push_back(num);
            res.insert(res.end(), cur.begin(), cur.end());
        }

        return res;
    }
};
