/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    int maxOperations(string s) {
        int ones = 0;
        char prev = '-';
        int res = 0;
        for (auto& c : s) {
            if (c == '1') {
                ones++;
            } else {
                if (prev == '1') {
                    res += ones;
                }
            }
            prev = c;
        }

        return res;
    }
};
