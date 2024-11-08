/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/generate-parentheses/
 * Runtime: 3ms (70.25%)
 */

class Solution {
public:
    vector<string> vec;

    vector<string> generateParenthesis(int n) {
        string s;
        int l = n, r = 0;
        dfs("", l, r);
        return vec;
    }

    void dfs(string s, int l, int r) {
        if (l > 0)
            dfs(s + "(", l - 1, r + 1);
        if (r > 0)
            dfs(s + ")", l, r - 1);

        if (l == 0 && r == 0)
            vec.push_back(s);
    }
};

