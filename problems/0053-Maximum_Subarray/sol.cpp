/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/maximum-subarray
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int sum = 0;

        for (auto& n : nums) {
            sum += n;
            res = max(sum, res);
            if (sum < 0) {
                sum = 0;
            }
        }

        return res;
    }
};
