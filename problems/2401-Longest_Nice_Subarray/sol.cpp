/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/longest-nice-subarray
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int cur = nums[0];
        int tail = 0;
        int curLen = 1;
        int res = 1;
        for (int i = 1; i < nums.size(); i++) {
            curLen++;
            while ((cur & nums[i]) != 0 && curLen > 1) {
                cur &= ~nums[tail++];
                curLen--;
            }
            cur |= nums[i];

            res = max(res, curLen);
        }

        return res;
    }
};
