/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/binary-prefix-divisible-by-5
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> res;
        res.reserve(nums.size());

        long long cur = 0;
        for (auto& n : nums) {
            cur <<= 1;
            cur += n;
            cur %= 5;
            if (cur == 0) {
                res.push_back(true);
            } else {
                res.push_back(false);
            }
        }

        return res;
    }
};
