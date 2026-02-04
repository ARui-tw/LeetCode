/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/longest-palindromic-substring
 * Runtime: 2 ms (98.29%)
 */

class Solution {
public:
    string longestPalindrome(string s) {
        string ss;
        ss.reserve(s.size() * 2 + 1);

        for (auto& c : s) {
            ss += "#";
            ss += c;
        }
        ss += "#";


        int maxRight = 0, center = 0;
        int n = ss.size();
        vector<int> RL(n, 1);

        int maxLen = 0;
        int resCenter = -1;

        for (int i = 0; i < n; i++) {
            if (i < maxRight) {
                RL[i] = min(RL[i - ((i - center) * 2)], maxRight - i);
            }

            while (i + RL[i] < n && i - RL[i] >= 0 && ss[i + RL[i]] == ss[i - RL[i]]) {
                RL[i]++;
            }

            if (RL[i] + i - 1 > maxRight) {
                maxRight = RL[i] + i -1;
                center = i;
            }

            if (maxLen < RL[i]) {
                maxLen = RL[i];
                resCenter = i / 2;
            }
        }

        maxLen--;

        return s.substr(resCenter - maxLen / 2, maxLen);
    }
};
