/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/maximum-subarray-sum-with-length-divisible-by-k
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long res = LLONG_MIN;
        long long n = nums.size();
        vector<long long> pre(k, LLONG_MAX);
        long long cur = 0;
        pre[k - 1] = 0;

        for (int i = 0; i < n; i++) {
            cur += nums[i];
            if (pre[i % k] != LLONG_MAX)
                res = max(res, cur - pre[i % k]);
            pre[i % k] = min(pre[i % k], cur);
        }

        return res;
    }
};
