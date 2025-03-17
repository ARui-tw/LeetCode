/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/divide-array-into-equal-pairs
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<bool> vec(500, false);
        int counter = 0;

        for (auto& n : nums) {
            if (vec[n]) {
                vec[n] = false;
                counter--;
            } else {
                vec[n] = true;
                counter++;
            }
        }

        return counter == 0;
    }
};
