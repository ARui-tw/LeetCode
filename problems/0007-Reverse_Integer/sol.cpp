/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/reverse-integer
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    int reverse(int x) {
        int res = 0;

        while (x) {
            if (res > INT_MAX / 10 || res < INT_MIN / 10) return 0;
            res *= 10;
            res += x % 10;

            x /= 10;  
        }

        return res;
    }
};
