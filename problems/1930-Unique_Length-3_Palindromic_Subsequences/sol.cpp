/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/unique-length-3-palindromic-subsequences
 * Runtime: 463 ms (29.76%)
 */

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<unordered_set<char>> valid(26, unordered_set<char>());
        vector<unordered_set<char>> pre(26, unordered_set<char>());
        unordered_set<char> seen;

        for (auto &c : s) {
            int cur = c - 'a';
            if (seen.count(cur) != 0) {
                valid[cur] = pre[cur];
                pre[cur].insert(cur);
            }
            else {
                seen.insert(cur);
            }
    
            for (int i = 0; i < pre.size(); i++) {
                if (i != cur && seen.count(i) != 0)
                    pre[i].insert(cur);
            }

        }

        int ans = 0;
        for (auto &v : valid) {
            ans += v.size();
        }

        return ans;
    }
};
