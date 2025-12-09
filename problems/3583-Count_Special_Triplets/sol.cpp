/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/count-special-triplets
 * Runtime: 549 ms (77.74%)
 */

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> right, left;
        long long res = 0;
        const int mod = 1e9 + 7;
        for (auto& num : nums) {
            right[num]++;
        }

        for (auto& num : nums) {
            int t = num * 2;
            right[num]--;
            if (right.count(t)) {
                res += (1LL * (left[t] % mod) * (right[t] % mod)) % mod;
                res %= mod;
            }
            left[num]++;
        }

        return res;
    }
};
