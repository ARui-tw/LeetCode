/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times
 * Runtime: 1 ms (87.38%)
 */

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int target = -1;
        long long res = 0;
        int curCount = 0;
        int prev = -1;

        for (int num : nums) {
            target = max(num, target);
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                curCount++;
                if (curCount >= k) {
                    while (nums[++prev] != target);
                    res += prev + 1;
                }
            } else if (curCount >= k) {
                res += prev + 1;
            }
        }

        return res;
    }
};
