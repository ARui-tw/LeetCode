/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/swim-in-rising-water
 * Runtime: 6 ms (67.04%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        queue<pair<int, int>> qu;
        queue<pair<int, int>> tmpqu;
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> seen(n, vector<bool>(m, false));
        int dirs[5] = {0, -1, 0, 1, 0};
        int t = 0;
        qu.push({0, 0});
        seen[0][0] = true;

        while (true) {
            int qs = qu.size();
            while (qs) {
                auto top = qu.front();
                qu.pop();

                if (grid[top.first][top.second] > t) {
                    qu.push(top);
                } else {
                    tmpqu.push(top);
                }

                while (!tmpqu.empty()) {
                    auto [x, y] = tmpqu.front();
                    tmpqu.pop();
                    if (x == n - 1 && y == m - 1) return t;
                    for (int i = 0; i < 4; i++) {
                        int nx = x + dirs[i];
                        int ny = y + dirs[i + 1];
                        if (nx >= 0 && ny >= 0 && nx < n && ny < m && !seen[nx][ny]) {
                            if (grid[nx][ny] <= t) {
                                seen[nx][ny] = true;
                                tmpqu.push({nx, ny});
                            } else {
                                seen[nx][ny] = true;
                                qu.push({nx, ny});
                            }
                        }
                    }
                }
                
                qs--;
            }
            t++;
        }
        
        return t;
    }
};
