/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores
 * Runtime: 1 ms (53.06%)
 */

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        int res = INT_MAX;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - k + 1; i++) {
            res = min(res, nums[i + k - 1] - nums[i]);
        }

        return res;
    }
};
