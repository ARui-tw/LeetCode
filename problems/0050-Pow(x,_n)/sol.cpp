/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/pow(x,-n)
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (x == 1) return 1;
        long long a = n;

        double res = 1;
        if (n < 0) {
            x = 1 / x;
            a = -a;
        }

        while (a) {
            if (a & 1) {
                res *= x;
                a--;
            }

            x *= x;
            a /= 2;
        }

        return res;
    }
};
