/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/grid-game
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long l = 0, r = 0;
        long long mi;
        long long ma;

        for (int i = 1; i < grid[0].size(); i++) {
            r += grid[0][i];
        }

        mi = r;

        for (int i = 1; i < grid[0].size(); i++) {
            l += grid[1][i-1];
            r -= grid[0][i];

            ma = max(r, l);
            mi = min(mi, ma);
            // cout << mi << endl;
        }

        return mi;

        /**
         *  1. recursive to find largest route?
         *      -> to slow
         *  2. Think of what 2nd bot can get
         *      -> First bot split the last few in first or first few in 2nd
         */
    }
};
