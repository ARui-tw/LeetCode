/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii
 * Runtime: 208 ms (16.04%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end());
        vector<vector<int>> mem(events.size(), vector<int>(k + 1, -1));

        auto dfs = [&](this const auto& self, int idx, int cnt) -> int {
            if (idx >= n) return 0;
            if (cnt == 0) return 0;
            if (mem[idx][cnt] != -1) return mem[idx][cnt];
            int val = events[idx][2];
            int end = events[idx][1];
            int nxtIdx;

            int l = idx + 1, r = n;
            while (l < r) {
                int mid = l + (r - l) / 2;
                if (events[mid][0] > end) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }

            int mid = l;

            return mem[idx][cnt] = max(val + self(mid, cnt - 1), self(idx + 1, cnt));
        };

        return dfs(0, k);
    }
};
