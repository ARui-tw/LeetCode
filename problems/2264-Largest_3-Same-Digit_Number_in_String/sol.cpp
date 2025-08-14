/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/largest-3-same-digit-number-in-string
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    string largestGoodInteger(string num) {
        int ma = -1;
        int cnt = 0;
        char prev = '-';
        char res = ' ';

        for (char& c : num) {
            if (c == prev) {
                cnt++;
            } else {
                cnt = 1;
            }
            if (cnt == 3 && ma < c - '0') {
                ma = c - '0';
                res = c;
            }
            prev = c;
        }

        return res == ' ' ? "" : string(3, res);
    }
};
