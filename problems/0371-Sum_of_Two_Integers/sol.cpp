/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/sum-of-two-integers
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    int getSum(int a, int b) {
        while (b) {
            unsigned carry = a & b;
            a = a ^ b;
            b = carry << 1;
        }

        return a;
    }
};
