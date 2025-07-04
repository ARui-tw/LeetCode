/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/find-the-k-th-character-in-string-game-ii
 * Runtime: 0 ms (100.00%)
 */

class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int i = 0;
        char res = 'a';
        k--;
        while (k) {
            bool kOne = k & 1;
            k >>= 1;
            bool op = operations[i++];
            if (kOne && op) res++;
            if (res > 'z') res = 'a';
        }

        return res;
    }
};
// 10: 1001
//     1010
