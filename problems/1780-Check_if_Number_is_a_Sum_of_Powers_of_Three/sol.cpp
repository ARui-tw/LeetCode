/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n != 0) {
            if (n % 3 != 0 && n % 3 != 1) return false;
            n /= 3;
        }

        return true;
    }
};
