/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/find-the-original-typed-string-i
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    int possibleStringCount(string word) {
        int res = 1;
        char prev = '-';
        int counter = 0;
        for (auto& c : word) {
            if (prev == c) {
                counter++;
            } else {
                if (counter != 0) {
                    res += counter - 1;
                }
                counter = 1;
            }
            prev = c;
        }

        if (counter != 0) {
            res += counter - 1;
        }

        return res;
    }
};
