/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-i
 * Runtime: 9 ms (82.11%)
 */

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        unordered_map<int, int> um;
        int n = nums.size();
        vector<int> res;
        vector<pair<int, int>> vec;

        auto xSum = [&]() -> int {
            for (auto [num, count] : um) {
                vec.push_back({count, num});
            }
            sort(vec.begin(), vec.end());
            int r = 0, need = x;
            while (need-- && vec.size()) {
                r += vec[vec.size() - 1].first * vec[vec.size() - 1].second;
                vec.pop_back();
            }
            vec.clear();

            return r;
        };

        for (int i = 0; i < k - 1; i++) {
            um[nums[i]]++;
        }

        for (int i = k - 1; i < n; i++) {
            if (i - k >= 0) {
                um[nums[i - k]]--;
            }
            um[nums[i]]++;

            res.push_back(xSum());
        }

        return res;
    }
};
