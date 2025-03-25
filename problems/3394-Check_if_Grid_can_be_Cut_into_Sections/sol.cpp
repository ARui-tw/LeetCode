/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections
 * Runtime: 49 ms (99.78%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        int m = rectangles.size();
        vector<pair<int, int>> edges;
        edges.reserve(m);

        for (int i = 0; i < m; i++) {
            edges.push_back({rectangles[i][0], rectangles[i][2]});
        }

        sort(edges.begin(), edges.end());

        int cur = edges[0].second;
        int count = 0;
        for (int i = 1; i < m; i++) {
            if (cur <= edges[i].first) {
                if (++count == 2) return true;
                cur = edges[i].second;
            } else {
                cur = max(edges[i].second, cur);
            }
        }

        edges.clear();
        edges.reserve(m);

        for (int i = 0; i < m; i++) {
            edges.push_back({rectangles[i][1], rectangles[i][3]});
        }

        sort(edges.begin(), edges.end());

        cur = edges[0].second;
        count = 0;
        for (int i = 1; i < m; i++) {
            if (cur <= edges[i].first) {
                if (++count == 2) return true;
                cur = edges[i].second;
            } else {
                cur = max(edges[i].second, cur);
            }
        }
        

        return false;
    }
};
