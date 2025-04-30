/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/find-numbers-with-even-number-of-digits
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        auto isEvenDigit = [](int n) {
            int i = 0;
            while (n) {
                n /= 10;
                i++;
            }
            return (i ^ 1) & 1;
        };

        int res = 0;
        for (auto n : nums) {
            res += isEvenDigit(n);
        }

        return res;
    }
};
