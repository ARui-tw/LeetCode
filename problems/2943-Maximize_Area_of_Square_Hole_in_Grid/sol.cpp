/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/maximize-area-of-square-hole-in-grid
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int hmax = 1, vmax = 1;

        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int cur = 0;
        for (int i = 0; i < hBars.size(); i++) {
            if (i > 0 && hBars[i - 1] == hBars[i] - 1) {
                cur++;
            } else {
                hmax = max(cur, hmax);
                cur = 2;
            }
        }
        hmax = max(cur, hmax);

        cur = 0;
        for (int i = 0; i < vBars.size(); i++) {
            if (i > 0 && vBars[i - 1] == vBars[i] - 1) {
                cur++;
            } else {
                vmax = max(cur, vmax);
                cur = 2;
            }
        }
        vmax = max(cur, vmax);

        int len = min(hmax, vmax);

        return len * len;
    }
};
