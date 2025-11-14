/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/increment-submatrices-by-one
 * Runtime: 23 ms (73.67%)
 */

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> res(n, vector<int>(n, 0));

        for (auto& q : queries) {
            res[q[0]][q[1]]++;

            if (q[2] + 1 < n) {
                res[q[2] + 1][q[1]]--;
            }

            if (q[3] + 1 < n) {
                res[q[0]][q[3] + 1]--;
            }

            if (q[2] + 1 < n && q[3] + 1 < n) {
                res[q[2] + 1][q[3] + 1]++;
            }
        }

        for (int i = 0; i < n; i++) {
            int cur = 0;
            for (int j = 0; j < n; j++) {
                cur += res[i][j];
                res[i][j] = cur;
            }
        }

        for (int i = 0; i < n; i++) {
            int cur = 0;
            for (int j = 0; j < n; j++) {
                cur += res[j][i];
                res[j][i] = cur;
            }
        }

        return res;
    }
};
