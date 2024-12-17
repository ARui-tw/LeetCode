/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/construct-string-with-repeat-limit
 * Runtime: 53 ms (41.52%)
 */

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        map<char, int, greater<char>> maps;
        string ans = "";

        for (char &c : s) {
            maps[c]++;
        }

        auto it = maps.begin();

        while (it != maps.end()) {
            int i;
            for (i = 0; i < repeatLimit; i++) {
                if (it->second > 0) {
                    ans += it->first;
                    it->second--;
                } else {
                    break;
                }
            }
            auto tmp_it = it;
            bool add = true;
            if (i == repeatLimit && it->second > 0) {
                tmp_it++;
                while (tmp_it != maps.end()) {
                    if (tmp_it->second > 0) {
                        ans += tmp_it->first;
                        tmp_it->second--;
                        add = false;
                        break;
                    }
                    tmp_it++;
                }
                if (tmp_it == maps.end()) {
                    return ans;
                }
            }

            if (add) ++it;
        }

        return ans;
    }
};
