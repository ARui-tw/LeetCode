/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/subsets-ii
 * Runtime: 0 ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int, int> um;
        vector<vector<int>> res(1, vector<int>());

        for (auto& n : nums) {
            um[n]++;
        }

        for (auto& u : um) {
            vector<vector<int>> cur(res.begin(), res.end());
            for (int i = 1; i <= u.second; i++) {
                vector<vector<int>> tmp(cur.begin(), cur.end());
                for (auto& t : tmp) {
                    for (int j = 0; j < i; j++) {
                        t.push_back(u.first);
                    }
                }
                res.insert(res.end(), tmp.begin(), tmp.end());
            }
        }

        return res;
    }
};
