/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold
 * Runtime: 17 ms (41.82%)
 */

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size(), m = mat[0].size();
        int res = 0;
        vector<vector<int>> pref(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                pref[i][j] = pref[i][j - 1] + mat[i - 1][j - 1];
            }
        }

        for (int j = 1; j <= m; j++) {
            for (int i = 2; i <= n; i++) {
                pref[i][j] += pref[i - 1][j];
            }
        }

        auto sum = [&](int x1, int y1, int x2, int y2) -> int {
            return pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 -1] + pref[x1 - 1][y1 - 1];
        };

        auto valid = [&](int k) -> bool {
            for (int i = 1; i <= n - k + 1; i++) {
                for (int j = 1; j <= m - k + 1; j++) {
                    if (sum(i, j, i + k - 1, j + k - 1) <= threshold) return true;
                }
            }

            return false;
        };

        int l = 1, r = min(m, n);
        int ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (valid(mid)) {
                l = mid + 1;
                ans = mid;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};
