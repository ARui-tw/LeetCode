/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/map-of-highest-peak
 * Runtime: 82 ms (55.46%)
 */

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<pair<int, pair<int, int>>> q;

        int n = isWater.size();
        int m = isWater[0].size();
        int dirX[] = {0, 1, -1, 0};
        int dirY[] = {-1, 0, 0, 1};
        vector<vector<int>> res(n, vector<int>(m, -1));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isWater[i][j] == 1) {
                    q.push({0, {i, j}});
                    res[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            // cout << "ji\n";
            auto [level, idxs] = q.front();
            auto [curX, curY] = idxs;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = curX + dirX[i];
                int ny = curY + dirY[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && res[nx][ny] == -1) {
                    res[nx][ny] = level + 1;
                    q.push({level + 1, {nx, ny}});
                }
            }
        }
       
       
        return res;
        /**
         *  1. multi-source bfs
         *      -> push the cell and its height(cur+1) if not visited
        */
    }
};
