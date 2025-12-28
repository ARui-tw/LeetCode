/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix
 * Runtime: 4 ms (1.28%)
 */

using int2 = pair<int, int>;
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> seen(n, vector<bool>(m, false));
        int res = 0;
        queue<int2> qu;
        if (grid[n-1][m-1] < 0) qu.push({n-1, m-1});

        while (!qu.empty()) {
            auto [x, y] = qu.front();
            res++;
            qu.pop();
            int nx = x - 1, ny = y - 1;
            if (nx >= 0 && grid[nx][y] < 0 && !seen[nx][y]) {
                seen[nx][y] = true;
                qu.push({nx, y});
            }
            if (ny >= 0 && grid[x][ny] < 0 && !seen[x][ny]) {
                seen[x][ny] = true;
                qu.push({x, ny});
            }
        }

        return res;
    }
};
