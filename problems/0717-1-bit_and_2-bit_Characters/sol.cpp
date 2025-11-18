/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/1-bit-and-2-bit-characters
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        bool res;
        for (int i = 0; i < bits.size(); i++) {
            if (bits[i] == 0) {
                res = true;
            } else {
                res = false;
                i++;
            }
        }

        return res;
    }
};
