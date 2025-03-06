/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/find-missing-and-repeated-values
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<bool> seen(n * n + 1, false);
        vector<int> res(2);
        long long sum = 0;

        for (auto &c : grid)
            for (auto &v : c) {
                if (!seen[v]) {
                    seen[v] = true;
                    sum += v;
                }
                else res[0] = v;
            }
        
        res[1] = (1 + n * n) * (n * n) / 2 - sum;
        
        return res;
    }
};
