/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/letter-tile-possibilities
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    int ans;
    unordered_map<int, int> count;
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        ans = 0;

        for (int i = 0; i < n; i++) {
            count[tiles[i] - 'A']++;
        }

        dfs();
        return ans;
    }

    void dfs() {
        for (auto& c : count) {
            if (c.second > 0) {
                ans++;
                c.second--;
                dfs();
                c.second++;
            }
        }
    }

};
