/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/count-good-numbers
 * Runtime: 0 ms (100.00%)
 */

#define MOD (int)1e9 + 7
class Solution {
public:
    int countGoodNumbers(long long n) {
        long long res = 1;
        long long base = 20;
        if (n & 1) {
            res = 5;
            n--;
        }
        n /= 2;

        while (n) {
            if (n & 1) res *= base;
            res %= MOD;

            base *= base;
            base %= MOD;
            n /= 2;
        }

        return res;
    }
};
