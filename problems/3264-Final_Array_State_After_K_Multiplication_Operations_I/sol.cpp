/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> ans(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
        }

        while (k--) {
            auto [a, b] = pq.top();
            a *= multiplier;
            pq.pop();
            nums[b] = a;
            pq.push({a, b});
        }

        return nums;
    }
};
