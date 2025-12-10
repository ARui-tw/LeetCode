/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/count-the-number-of-computer-unlocking-permutations
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        long long res = 1;
        const int mod = 1e9 + 7;

        for (int i = 1; i < complexity.size(); i++) {
            if (complexity[i] <= complexity[0]) return 0;
            res *= i;
            res %= mod;
        }

        return res;
    }
};
