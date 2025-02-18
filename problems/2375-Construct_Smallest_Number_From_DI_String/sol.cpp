/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/construct-smallest-number-from-di-string
 * Runtime: 0 ms (100.00%)
 */

class Solution {
    string res;
    vector<bool> used;
    string pattern;
    int n;

public:
    string smallestNumber(string pattern) {
        res = "";
        used.resize(10, 0);
        n = pattern.size();
        this->pattern = pattern;

        for (int i = 1; i <= 9; i++) {
            res = '0' + i;
            used[i] = true;
            if (dfs(0))
                return res;
            used[i] = false;
        }

        return "";
    }

    bool dfs(int pos) {
        if (pos == n)
            return true;

        for (int i = 1; i <= 9; i++) {
            if (!used[i]) {
                if ((pattern[pos] == 'I' && i > res.back() - '0') ||
                    (pattern[pos] == 'D' && i < res.back() - '0')) {
                    res += '0' + i;
                    used[i] = true;
                    if (dfs(pos + 1))
                        return true;
                    res.pop_back();
                    used[i] = false;
                }
            }
        }

        return false;
    }
};
