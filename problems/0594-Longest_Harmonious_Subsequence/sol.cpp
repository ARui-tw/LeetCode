/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/longest-harmonious-subsequence
 * Runtime: 28 ms (45.14%)
 */

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto& n : nums) {
            m[n]++;
        }

        int prev_num = INT_MAX;
        int prev_count = 0;
        int res = 0;
        for (auto& [n, c] : m) {
            if (m.count(n + 1)) {
                res = max(res, c + m[n + 1]);
            }
        }

        return res;
    }
};
