/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/number-of-ways-to-split-array
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long leftSum = 0, rightSum = 0;
        int res = 0;
        for (auto& n : nums) {
            rightSum += n;
        }

        for (int i = 0; i < nums.size() - 1; i++) {
            rightSum -= nums[i];
            leftSum += nums[i];
            // printf("%d: %d\n", i, nums[i]);
            if (leftSum >= rightSum) {
                // printf("%d: %d\n", i, nums[i]);
                res++;
            }
        }
        

        return res;
    }
};
