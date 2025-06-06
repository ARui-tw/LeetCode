/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/palindromic-substrings
 * Runtime: 3 ms (88.17%)
 */

class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; i - j >= 0 && i + j < s.size(); j++) {
                if (s[i + j] == s[i - j]) res++;
                else break;
            }
            if (i != 0 && s[i - 1] == s[i]) {
                for (int j = 0; (i - 1) - j  >= 0 && i + j < s.size(); j++) {
                    if (s[i + j] == s[i - 1 - j]) res++;
                    else break;
                }
            }
        }

        return res;
    }
};
