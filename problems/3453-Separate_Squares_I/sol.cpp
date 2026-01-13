/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/separate-squares-i
 * Runtime: 100 ms (61.56%)
 */

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double l = 0, r = 2 * 1e9;

        auto diff = [&](double line) -> double {
            double top = 0, bot = 0;
            for (auto& s : squares) {
                long long y = s[1], h = s[2];
                if (y + h <= line) {
                    bot += h * h;
                } else if (y >= line) {
                    top += h * h;
                } else {
                    top += (y + h - line) * h;
                    bot += (line - y) * h;
                }
            }
            return top - bot;
        };

        while (r - l >= 0.00001) {
            double mid = l + (r - l) / 2;
            double d = diff(mid);

            if (d > 0) {
                l = mid;
            } else {
                r = mid;
            }
        }

        return r;
    }
};
