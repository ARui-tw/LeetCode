/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/find-lucky-integer-in-an-array
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> um;
        for (auto& a : arr) {
            um[a]++;
        }

        int res = -1;
        for (auto& [k, v] : um) {
            if (k == v) res = max(res, k);
        }

        return res;
    }
};
