/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/count-covered-buildings
 * Runtime: 704 ms (36.46%)
 */

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int s = buildings.size();
        unordered_map<int, unordered_map<int, bool>> out;
        sort(buildings.begin(), buildings.end());
        int cur = -1;
        for (int i = 0; i < s; i++) {
            int x = buildings[i][0], y = buildings[i][1];
            if (cur < x) {
                out[x][y] = true;
                if (i > 0) {
                    out[buildings[i - 1][0]][buildings[i - 1][1]] = true;
                }
            }
            cur = x;
        }
        if (s > 0)
            out[buildings[s - 1][0]][buildings[s - 1][1]] = true;

        sort(buildings.begin(), buildings.end(), [](const auto& lfs, const auto& rfs) {
            return lfs[1] != rfs[1] ? lfs[1] < rfs[1] : lfs[0] < rfs[0];
        });

        cur = -1;
        for (int i = 0; i < s; i++) {
            int x = buildings[i][0], y = buildings[i][1];
            if (cur < y) {
                out[x][y] = true;
                if (i > 0) {
                    out[buildings[i - 1][0]][buildings[i - 1][1]] = true;
                }
            }
            cur = y;
        }

        if (s > 0)
            out[buildings[s - 1][0]][buildings[s - 1][1]] = true;

        int cnt = 0;
        for (auto& [i, j] : out) {
            cnt += j.size();
        }

        return s - cnt;
    }
};
