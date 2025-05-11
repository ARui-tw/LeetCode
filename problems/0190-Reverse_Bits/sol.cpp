/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/reverse-bits
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int count = 32;

        while (n) {
            res <<= 1;
            res += n & 1;
            n >>= 1;
            count--;
        }

        while (count--) {
            res <<= 1;
        }

        return res;
    }
};
