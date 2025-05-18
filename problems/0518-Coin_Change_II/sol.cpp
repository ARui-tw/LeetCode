/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/coin-change-ii
 * Runtime: 3 ms (95.02%)
 */

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<uint> mem(amount + 1, 0);
        mem[amount] = 1;

        for (auto &coin : coins) {
            for (int i = amount; i >= 0; i--) {
                if (i - coin >= 0) {
                    mem[i - coin] += mem[i];
                }
            }
        }

        return mem[0];
    }
}
