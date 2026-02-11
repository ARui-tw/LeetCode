/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/minimum-window-substring
 * Runtime: 4 ms (71.82%)
 */

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> um;
        int rem = t.size();
        int minSize = s.size();
        int minStart = 0;
        for (auto& c : t) {
            um[c]++;
        }

        int l = 0, r = 0;
        while (rem && r < s.size()) {
            if (um.count(s[r])) {
                if (um[s[r]]-- > 0) {
                    rem--;
                }
            }
            r++;
        }

        if (rem) return "";

        minSize = r;
        // printf("Init %d %d\n", minSize, minStart);

        while (l < s.size()) {
            if (um.count(s[l])) {
                if (++um[s[l]] > 0) {
                    rem++;
                }
            }

            while (rem && r < s.size()) {
                if (um.count(s[r])) {
                    if (um[s[r]]-- > 0) {
                        rem--;
                    }
                }
                r++;
            }

            if (rem) break;
            
            if (r - l - 1 < minSize) {
                minSize = r - l - 1;
                minStart = l + 1;
                // printf("%d %d\n", minSize, minStart);
            }

            l++;
        }

        // printf("Final %d %d\n", minSize, minStart);
        return s.substr(minStart, minSize);
    }
};
