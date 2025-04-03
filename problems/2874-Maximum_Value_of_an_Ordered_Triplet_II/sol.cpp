/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long res = 0;
        int maxIJ = 0;
        int maxI = 0;

        for (auto n : nums) {
            res = max(res, 1LL * maxIJ * n);
            maxIJ = max(maxIJ, maxI - n);
            maxI = max(maxI, n);
        }

        return res;
    }
};
