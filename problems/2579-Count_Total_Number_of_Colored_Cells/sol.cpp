/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/count-total-number-of-colored-cells
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    long long coloredCells(int n) {
        return (long long)n * (n-1) * 2 + 1;
    }
};
