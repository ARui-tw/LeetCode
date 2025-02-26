/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum = 0, curPosSum = 0, curNegSum = 0;

        for (auto& n : nums) {
            curPosSum = max(0, curPosSum + n);
            curNegSum = min(0, curNegSum + n);
            sum = max({sum, curPosSum, curNegSum * -1});
        }

        return sum;
    }
};
