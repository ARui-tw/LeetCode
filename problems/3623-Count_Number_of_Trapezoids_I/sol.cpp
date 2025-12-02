/**
 * Author: ARui<mail@arui.dev>
 * Problem: https://leetcode.com/problems/count-number-of-trapezoids-i
 * Runtime: 64 ms (68.68%%)
 */

int mod = 1e9 + 7;
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<long long, long long> um;
        vector<long long> cnt;

        for (auto& p : points) {
            um[p[1]]++;
        }

        for (auto& [x, c] : um) {
            cnt.push_back((((long long)c * (c - 1)) / 2) % mod);
       }

       long long res = 0;
       long long cur = 0;

        for (auto& c : cnt) {
            res += (c * cur) % mod;
            res %= mod;
            cur += c;
        }


        return res;
    }
};
