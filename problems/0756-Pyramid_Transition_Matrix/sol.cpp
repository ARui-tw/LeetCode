/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/pyramid-transition-matrix
 * Runtime: 2326 ms (5.41%)
 */

class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> um;
        for (auto& a : allowed) {
            um[a.substr(0, 2)].push_back(a[2]);
        }
        auto dfs = [&](this const auto &self, string bot, int idx, string cur) -> bool {
            if (bot.size() == 1) return true;
            if (idx >= bot.size() - 1) {
                return self(cur, 0, "");
            }

            for (auto& c : um[bot.substr(idx, 2)]) {
                if(self(bot, idx+1, cur + c)) return true;
            }
            return false;
        };

        return dfs(bottom, 0, "");
    }
};
