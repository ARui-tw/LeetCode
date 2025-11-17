/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int prev = -1 * k - 1;
        for (int i = 0; i < nums.size(); i++ ) {
            if (nums[i] == 1) {
                if (i - prev - 1 < k) return false;
                prev = i;
            }
        }

        return true;
    }
};
