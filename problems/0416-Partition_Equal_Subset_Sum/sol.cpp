/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/partition-equal-subset-sum
 * Runtime: 84 ms (76.37%)
 */

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;
        sum /= 2;

        vector<bool> seen(sum + 1, false);
        seen[0] = true;

        for (auto& num : nums) {
            for (int i = sum; i >= num; i--) {
                seen[i] = seen[i] | seen[i - num];
            }
        }

        return seen[sum];
    }
};
