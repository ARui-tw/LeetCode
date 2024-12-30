/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/count-ways-to-build-good-strings
 * Runtime: 10 ms (34.25%)
 */

class Solution {
    vector<int> mem;
    int low;
    int high;
    int zero;
    int one;
    int mod = 1000000007;

public:
    int countGoodStrings(int low, int high, int zero, int one) {

        mem.resize(high+1, -1);
        this->low = low;
        this->high = high;
        this->zero = zero;
        this->one = one;

        return sol(0);
    }
    int sol(int cur) {
        if (mem[cur] != -1) {
            return mem[cur];
        }
        long long ret = 0;
        if (cur >= low) {
            ret++;
        }

        if (cur + zero <= high) {
            ret += sol(cur + zero);
            ret %= mod;
        }
        if (cur + one <= high) {
            ret += sol(cur + one);
            ret %= mod;
        }

        mem[cur] = ret;

        return ret;
    }
};
