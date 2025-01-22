/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/01-matrix
 * Runtime: 26 ms (36.86%)
 */

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int dir[] = {1, 0, -1, 0, 1};
        queue<pair<int, pair<int, int>>> qu;
        vector<vector<int>> res(n, vector<int>(m, -1));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    qu.push({0, {i, j}});
                    res[i][j] = 0;
                }
            }
        }

        while(!qu.empty()) {
            auto [dist, idx] = qu.front();
            auto [x, y] = idx;
            qu.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dir[i];
                int ny = y + dir[i+1];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m && res[nx][ny] == -1) {
                    res[nx][ny] = dist+1;
                    qu.push({dist+1, {nx, ny}});
                }
            }
        }

        return res;
    }
};
