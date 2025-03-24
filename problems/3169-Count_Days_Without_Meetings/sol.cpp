/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/count-days-without-meetings
 * Runtime: 65 ms (73.30%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int res = 0;
        int cur = 0;
        int n = meetings.size();

        sort(meetings.begin(), meetings.end());

        for (int i = 1; i <= days; i++) {
            if (cur == n) {
                res += days - i + 1;
                return res;
            }

            if (meetings[cur][0] > i) {
                res += meetings[cur][0] - i;
                i = max(meetings[cur][1], i);
                cur++;
                while (cur < n && meetings[cur][0] <= i) {
                    i = max(meetings[cur][1], i);
                    cur++;
                }
            } else {
                i = max(meetings[cur][1], i);
                cur++;
                while (cur < n && meetings[cur][0] <= i) {
                    i = max(meetings[cur][1], i);
                    cur++;
                }
            }
        }

        return res;
    }
};
