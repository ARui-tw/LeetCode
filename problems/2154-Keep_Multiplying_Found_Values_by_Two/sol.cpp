/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/keep-multiplying-found-values-by-two
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        vector<bool> exist(1001, 0);

        for (auto& num : nums) {
            exist[num] = true;
        }

        while (original < 1001 && exist[original]) {
            original *= 2;
        }

        return original;
    }
};
