/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/count-the-hidden-sequences
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long mi = 0;
        long long ma = 0;
        long long cur = 0;

        for (auto d : differences) {
            cur = cur + d;
            mi = min(cur, mi);
            ma = max(cur, ma);
        }

        ma -= (mi - lower);

        int ans = upper - ma + 1;

        return ans > 0 ? ans : 0;
    }
};
