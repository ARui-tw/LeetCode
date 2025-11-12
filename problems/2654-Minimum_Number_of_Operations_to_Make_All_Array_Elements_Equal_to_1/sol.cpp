/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int curGcd;
        int minSub = INT_MAX;
        int notOne = 0;
        for (int i = 0; i < nums.size(); i++) {
            curGcd = nums[i];
            notOne += nums[i] == 1 ? 0 : 1;

            for (int j = i - 1; j >= 0; j--) {
                curGcd = gcd(nums[j], curGcd);
                if (curGcd == 1) {
                    minSub = min(minSub, i - j + 1);
                    break;
                }
            }
        }
        
        return minSub == INT_MAX ? -1 : minSub - 2 + notOne;
    }
};
