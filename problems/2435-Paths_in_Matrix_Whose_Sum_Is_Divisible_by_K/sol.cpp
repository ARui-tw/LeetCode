/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k
 * Runtime: 213 ms (79.86%)
 */

int mod = 1e9 + 7;
class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> map(n, vector<vector<int>>(m, vector<int>(k, 0)));
        map[0][0][grid[0][0] % k] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int cur = grid[i][j];
                if (i) {
                    for (int l = 0; l < k; l++) {
                        int nxt = (l + cur) % k;
                        map[i][j][nxt] += map[i-1][j][l];
                        map[i][j][nxt] %= mod;
                    }
                }

                if (j) {
                    for (int l = 0; l < k; l++) {
                        int nxt = (l + cur) % k;
                        map[i][j][nxt] += map[i][j-1][l];
                        map[i][j][nxt] %= mod;
                    }
                }
            }
        }

        return map[n-1][m-1][0];
    }
};
