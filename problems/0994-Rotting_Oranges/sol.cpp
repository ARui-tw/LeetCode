/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/rotting-oranges
 * Runtime: 0 ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
    int dirX[4] = {1, -1, 0, 0};
    int dirY[4] = {0, 0, -1, 1};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> qu;
        int n = grid.size();
        int m = grid[0].size();
        int total = 0, res = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2)
                    qu.push({i, j}); 
                else if (grid[i][j] == 1)
                    total++;
            }
        }

        if (total == 0) return res;

        while (!qu.empty()) {
            int c = qu.size();
            res++;
            while (c--) {
                auto [curX, curY] = qu.front();
                qu.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = dirX[i] + curX;
                    int ny = dirY[i] + curY;
                    if (nx < n && nx >= 0 && ny < m && ny >= 0 && grid[nx][ny] == 1) {
                        qu.push({nx, ny});
                        grid[nx][ny] = 2;
                        total--;
                        if (total == 0) {
                            return res;
                        }
                    }
                }
            }
        }

        return -1;
    }
};
