/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/first-completely-painted-row-or-column
 * Runtime: 2 ms (99.09%)
 */

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<pair<int, int>> loc(n * m + 1);
        vector<int> x(m, n);
        vector<int> y(n, m);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                loc[mat[i][j]] = {i, j};
            }
        }

        for (int idx = 0; idx < arr.size(); idx++) {
            int a = arr[idx];
            auto [i, j] = loc[a];

            if (--x[j] == 0) return idx;
            if (--y[i] == 0) return idx;
        }

        return 0;
    }
};
