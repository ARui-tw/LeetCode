/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/minimize-maximum-pair-sum-in-array
 * Runtime: 151 ms (95.7%)
 */

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int res = INT_MIN;
        for (int i = 0; i < n / 2; i++) {
            res = max(res, nums[i] + nums[n - i - 1]);
        }

        return res;
    }
};
