/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/count-symmetric-integers
 * Runtime: 13 ms (83.26%)
 */

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;

        for (int i = low; i <= high; i++) {
            int digits = 0;
            int tmp = i;
            int total = 0;
            int first = 0;
            while (tmp) {
                total += tmp % 10;
                tmp /= 10;
                digits++;
            }

            if (digits & 1) {
                i = pow(10, digits);
                continue;
            }

            digits /= 2;
            tmp = i;

            while (digits--) {
                first += tmp % 10;
                tmp /= 10;
            }

            // cout << first << " " << total << endl;

            count += (first * 2 == total)? 1 : 0;
        }

        return count;
    }
};
