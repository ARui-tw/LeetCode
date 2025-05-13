/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/number-of-islands
 * Runtime: 26 ms (64.55%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();
int dirX[] = {1, 0, 0, -1};
int dirY[] = {0, -1, 1, 0};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> seen(n, vector<bool>(m, false));
        queue<pair<int, int>> qu;
        int res = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !seen[i][j]) {
                    res++;
                    qu.push({i, j});
                    seen[i][j] = true;
                    while (!qu.empty()) {
                        auto [curX, curY] = qu.front();
                        qu.pop();

                        for (int k = 0; k < 4; k++) {
                            int nx = curX + dirX[k];
                            int ny = curY + dirY[k];

                            if (nx >= 0 && ny >= 0 && nx < n && ny < m && !seen[nx][ny] && grid[nx][ny] == '1') {
                                qu.push({nx, ny});
                                seen[nx][ny] = true;
                            }
                        }

                    }
                }
            }
        }

        return res;
    }
};
