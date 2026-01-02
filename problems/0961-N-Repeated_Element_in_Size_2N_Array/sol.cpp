/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/n-repeated-element-in-size-2n-array
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        bitset<10001> seen;
        for (auto num : nums) {
            if (seen[num]) return num;
            seen[num].flip();
        }

        return -1;
    }
};
