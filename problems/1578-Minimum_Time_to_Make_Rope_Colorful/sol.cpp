/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/minimum-time-to-make-rope-colorful
 * Runtime: 4 ms (59.28%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        char prev = '-';
        int n = colors.size();
        int res = 0;
        int curMax = -1;
        for (int i = 0; i < n; i++) {
            if (prev == colors[i]) {
                if (curMax == -1) {
                    curMax = neededTime[i-1];
                }

                res += min(neededTime[i], curMax);
                curMax = max(curMax, neededTime[i]);
            } else {
                curMax = -1;
            }

            prev = colors[i];
        }

        return res;
    }
};
