/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/clear-digits
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    string clearDigits(string s) {
        string res;
        int counter = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] >= '0' && s[i] <= '9') {
                counter++;
            } else {
                if (counter == 0) {
                    res = s[i] + res;
                } else {
                    counter--;
                }
            }
            
        }

        return res;
    }
};
