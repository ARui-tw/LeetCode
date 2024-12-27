/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/best-sightseeing-pair
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int best = values[0];
        int res = INT_MIN;

        for (int i = 1; i < values.size(); i++) {
            best--;
            res = max(res, best + values[i]);
            if (best < values[i]) {
                best = values[i];
            }
        }

        return res;
    }
};
