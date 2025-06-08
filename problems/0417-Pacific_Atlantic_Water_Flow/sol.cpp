/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/pacific-atlantic-water-flow
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> able (n, vector<int>(m, 0));
        queue<pair<int, int>> qu;
        vector<vector<bool>> seen(n, vector<bool>(m, false));
        int dirs[5] = {0, 1, 0, -1, 0};

        for (int i = 0; i < n; i++) {
            qu.push({i, 0});
            seen[i][0] = true;
        }

        for (int i = 1; i < m; i++) {
            qu.push({0, i});
            seen[0][i] = true;
        }

        while (!qu.empty()) {
            auto [x, y] = qu.front();
            able[x][y]++;
            qu.pop();
                    // printf("able: %d, %d\n", x, y);
            int prevHeight = heights[x][y];
            for (int i = 0; i < 4; i++) {
                int nx = x + dirs[i];
                int ny = y + dirs[i + 1];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m && !seen[nx][ny] && prevHeight <= heights[nx][ny]) {
                    // printf("%d, %d\n", nx, ny);
                    seen[nx][ny] = true;
                    qu.push({nx, ny});
                }
            }
        }   

        // printf("========\n");
        vector<vector<bool>> seen2(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            qu.push({i, m - 1});
            seen2[i][m - 1] = true;
        }

        for (int i = 0; i < m - 1; i++) {
            qu.push({n - 1, i});
            seen2[n - 1][i] = true;
        }

        while (!qu.empty()) {
            auto [x, y] = qu.front();
            able[x][y]++;
                    // printf("able: %d, %d\n", x, y);
            qu.pop();
            int prevHeight = heights[x][y];
            for (int i = 0; i < 4; i++) {
                int nx = x + dirs[i];
                int ny = y + dirs[i + 1];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m && !seen2[nx][ny] && prevHeight <= heights[nx][ny]) {
                    // printf("%d, %d\n", nx, ny);
                    seen2[nx][ny] = true;
                    qu.push({nx, ny});
                }
            }
        }


        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (able[i][j] == 2) res.push_back({i, j});
            }
        }

        return res;
    }
};
