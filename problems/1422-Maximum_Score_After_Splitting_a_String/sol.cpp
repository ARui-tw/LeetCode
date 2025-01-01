/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/maximum-score-after-splitting-a-string
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    int maxScore(string s) {
        int ones = 0;
        int zero = 0;
        int sol = -1;
        
        for (auto& c : s) {
            if (c == '1') ones++;
        }

        for (int i = 0; i < s.size() - 1; i++) {
            char c = s[i];
            if (c == '0') zero++;
            else if (c == '1') ones--;
            sol = max(sol, ones + zero);
        }

        return sol;
    }
};
