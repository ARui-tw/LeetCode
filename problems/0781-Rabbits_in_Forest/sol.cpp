/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/rabbits-in-forest
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> um;
        int res = 0;

        for (auto a : answers) {
            if (um.count(a) && um[a] != 0) {
                um[a]--;
            } else {
                res += a + 1;
                um[a] = a;
            }
        }

        return res;
    }
};
