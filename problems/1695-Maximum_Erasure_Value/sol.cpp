/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/maximum-erasure-value
 * Runtime: 183 ms (48.53%)
 */

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int res = 0;
        unordered_set<int> us;
        int head = 0;
        us.insert(nums[0]);
        res += nums[0];
        int ma = res;
        for (int i = 1; i < nums.size(); i++) {
            while (us.count(nums[i])) {
                us.erase(nums[head]);
                res -= nums[head];
                head++;
            }
            res += nums[i];
            us.insert(nums[i]);
            ma = max(res, ma);
        }

        return ma;
    }
};
