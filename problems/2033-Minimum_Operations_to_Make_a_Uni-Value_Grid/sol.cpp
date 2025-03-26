/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid
 * Runtime: 20 ms (88.75%)
 */

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        int mod = grid[0][0] % x;
        vector<int> vec(n*m, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] % x != mod) return -1;
                vec[i * m + j] = grid[i][j];
            }
        }

        nth_element(vec.begin(), vec.begin() + (n * m / 2), vec.end());

        int target = vec[n * m / 2];

        for (auto& c : vec) {
            res += abs((target - c) / x);
        }

        return res;
    }
};
