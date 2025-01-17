/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/neighboring-bitwise-xor
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        bool init = false;
        for (int d : derived) {
            if (d == 1) init = !init;
            // cout << init << " ";
        }

        return init == 0;
    }
};
