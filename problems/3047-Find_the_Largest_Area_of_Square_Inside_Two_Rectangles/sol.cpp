/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/find-the-largest-area-of-square-inside-two-rectangles
 * Runtime: 111 ms (45.04%)
 */

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long res = 0;
        int n = bottomLeft.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long x1 = min(topRight[i][0], topRight[j][0]);
                long long x2 = max(bottomLeft[i][0], bottomLeft[j][0]);
                long long y1 = min(topRight[i][1], topRight[j][1]);
                long long y2 = max(bottomLeft[i][1], bottomLeft[j][1]);

                long long x = x1 - x2;
                long long y = y1 - y2;

                if (x > 0 && y > 0) {
                    res = max(res, min(x, y));
                }
            }
        }

        return res * res;
    }
};
