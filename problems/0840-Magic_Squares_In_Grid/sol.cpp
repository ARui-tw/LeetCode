/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/magic-squares-in-grid
 * Runtime: 2 ms (12.3%)
 */

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int res = 0;
        int cur = 0;

        auto isMagic = [&](int i, int j) -> bool {
            unordered_set<int> us;
            int cnt = 0;

            for (int k = i; k < i + 3; k++) {
                cnt = 0;
                for (int l = j; l < j + 3; l++) {
                    int num = grid[k][l];
                    if (num == 0 || num > 9) return false;
                    us.insert(num);
                    cnt += num;
                }
                if (cnt != 15) return 0;
            }

            for (int k = j; k < j + 3; k++) {
                cnt = 0;
                for (int l = i; l < i + 3; l++) {
                    int num = grid[l][k];
                    cnt += num;
                }
                if (cnt != 15) return 0;
            }

            if (us.size() != 9) return false;

            cnt = 0;
            for (int k = 0; k < 3; k++) {
                cnt += grid[i + k][j + k];
            }
            if (cnt != 15) return 0;

            cnt = 0;
            for (int k = 0; k < 3; k++) {
                cnt += grid[i + 2 - k][j + k];
            }
            if (cnt != 15) return 0;

            return true;
        };
        
        if (n < 2 || m < 2) return 0;

        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < m - 2; j++) {
                res += isMagic(i, j);
            }
        }

        return res;
    }
};
