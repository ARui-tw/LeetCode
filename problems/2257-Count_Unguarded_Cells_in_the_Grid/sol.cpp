/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/count-unguarded-cells-in-the-grid
 * Runtime: 54 ms (77.52%)
 */

#define WALL 1
#define GUARD 2
#define SAFE 3
#define UNSAFE 4
class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> vec(m, vector<int>(n, SAFE));
        int res = m * n - guards.size() - walls.size();
        for (auto& guard : guards) {
            vec[guard[0]][guard[1]] = GUARD;
        }
        for (auto& wall : walls) {
            vec[wall[0]][wall[1]] = WALL;
        }

        for (int i = 0; i < m; i++) {
            int cur = SAFE;
            for (int j = 0; j < n; j++) {
                if (vec[i][j] == GUARD) {
                    cur = UNSAFE;
                } else if (vec[i][j] == WALL) {
                    cur = SAFE;
                } else {
                    if (vec[i][j] == SAFE && cur == UNSAFE) {
                        res--;
                        vec[i][j] = cur;
                    }
                }
            }
        }

        for (int i = 0; i < m; i++) {
            int cur = SAFE;
            for (int j = n - 1; j >= 0; j--) {
                if (vec[i][j] == GUARD) {
                    cur = UNSAFE;
                } else if (vec[i][j] == WALL) {
                    cur = SAFE;
                } else {
                    if (vec[i][j] == SAFE && cur == UNSAFE) {
                        res--;
                        vec[i][j] = cur;
                    }
                }
            }
        }

        for (int j = 0; j < n; j++) {
            int cur = SAFE;
            for (int i = 0; i < m; i++) {
                if (vec[i][j] == GUARD) {
                    cur = UNSAFE;
                } else if (vec[i][j] == WALL) {
                    cur = SAFE;
                } else {
                    if (vec[i][j] == SAFE && cur == UNSAFE) {
                        res--;
                        vec[i][j] = cur;
                    }
                }
            }
        }

        for (int j = 0; j < n; j++) {
            int cur = SAFE;
            for (int i = m - 1; i >= 0; i--) {
                if (vec[i][j] == GUARD) {
                    cur = UNSAFE;
                } else if (vec[i][j] == WALL) {
                    cur = SAFE;
                } else {
                    if (vec[i][j] == SAFE && cur == UNSAFE) {
                        res--;
                        vec[i][j] = cur;
                    }
                }
            }
        }

        return res;
    }
};
