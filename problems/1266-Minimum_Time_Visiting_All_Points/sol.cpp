/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/minimum-time-visiting-all-points
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;

        for (int i = 1; i < points.size(); i++) {
            int prevX = points[i-1][0], prevY = points[i-1][1];
            int x = points[i][0], y = points[i][1];
            int diffX = abs(prevX - x), diffY = abs(prevY - y);

            res += diffX + diffY - min(diffX, diffY);
        }

        return res;
    }
};
